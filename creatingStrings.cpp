// Solution to Creating Strings question under the CSES Introductary Problem set
// Author: Vishvesh Trivedi (NerdyVisky)

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

#define pb push_back
#define all(str) str.begin(), str.end()

int main()
{
    string str;
    cin>>str;
    sort(all(str));
    ll count = 0;
    vector<string> permutations;
    do{
        permutations.pb(str);
        count++;
    }while(next_permutation(all(str)));

    cout<<(count)<<endl;
    for(int i = 0; i<count; i++){
        cout<<(permutations[i])<<endl;
    }
    return 0;
}