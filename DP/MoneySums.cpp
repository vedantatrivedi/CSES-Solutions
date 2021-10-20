#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mxN = 100, mxX = 1e5; // mxX -> 100 x 1000 = 1e5 i.e max sum possible
int n , x[mxN], dp[mxX+1]; // dp[i]=1 -> means that  "sum i" is achievable ;


int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
    }
    dp[0] =1; // BASE CASE , sum = 0 possible if we take 0 coins

    for (int j = 0; j < n; ++j)
    {
        for (int i = mxX; i  ; --i)
        {
            if( i>= x[j] ){
                dp[i]|=dp[i-x[j]] ;
            }
        }
    }

    // OR
    
    // for (int j = n-1; j>=0 ; --j)
    // {
    //     for (int i = mxX; i  ; --i)
    //     {
    //         if( i>= x[j] ){
    //             dp[i]|=dp[i-x[j]] ;
    //         }
    //     }
    // }
    vector<int> ans;
    for (int i = 1; i <= 1e5; ++i)
    {
        if( dp[i] )
            ans.push_back(i);
    }

    cout << ans.size() << "\n";
    for( int a : ans ){
        cout << a << " ";
    }
    
    return 0;   
}




















































// Below approach gives TLE
// #include <bits/stdc++.h>
// #define ll long long
// #define ar array
// using namespace std;

// const int mxN = 1e2;
// int n;
// set <ll> ans;
// int a[mxN];

// int main() {
// 	cin >> n;
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> a[i];
//     }
//     for (int i = 0; i < pow(2,n); ++i)
//     {
//         int shift = i;
//         ll sum = 0;
//         for (int j=0; j<n && shift>=0; ++j) {
//             if(shift & 1) sum += a[j];
//             //cout << "i " << i <<  " " << (i & 1) << "\t";
//             shift=shift>>1; // Right shift i by 1
//         }
//         ans.insert( sum );
//     }
//     cout << ans.size()-1 << "\n";
//     for( auto i : ans ){
//         if( i!=0 )
//         cout << i << " ";
//     }
// 	return 0;	
// }
