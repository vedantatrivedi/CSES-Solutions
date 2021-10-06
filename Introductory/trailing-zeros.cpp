// Author: Vishvesh Trivedi (NerdyVisky)
// Solution to the problem - Trailing Zeros under the CSES Introductory Problem set.

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int trail_zero(ll n){
    int zeros = 0;
    for(ll i = 5; i<=n; i*=5)
    {
        zeros = zeros + n/i;
    }
    return zeros;
    
}

int main(){
    ll n;
    cin>>n;
    cout<<(trail_zero(n));
    return 0;
}