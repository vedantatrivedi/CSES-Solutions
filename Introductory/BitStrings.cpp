#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    ll res = 1;
    while(n--)
    {
        res <<= 1;
        res %= 1'000'000'007;
    }

    cout << res << endl;
    
    return 0;
}