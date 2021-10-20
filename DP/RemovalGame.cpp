// link : https://leetcode.com/problems/predict-the-winner/discuss/96828/JAVA-9-lines-DP-solution-easy-to-understand-with-improvement-to-O(N)-space-complexity.
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 5e3;

ll t[mxN],dp[mxN][mxN]; // dp[x][y] ->  how much more scores that the first-in-action player will get from i to j than the second player.
ll n;

ll getDiff() {
    
    for (ll i = 0; i < n; i++) { dp[i][i] = t[i]; }
    for (ll len = 1; len < n; len++) {
        for (ll i = 0; i < n - len; i++) {
            ll j = i + len;
            dp[i][j] = max(t[i] - dp[i + 1][j], t[j] - dp[i][j - 1]);
        }
    }

    // for (ll i = 0; i < n; ++i)
    // {
    // 	for (ll j = 0; j < n; ++j)
    // 	{
    // 		cout << dp[i][j] << " ";
    // 	}
    // 	cout << "\n";
    // }

    return dp[0][n - 1];
}

int main() {
	
	ll sum = 0;
	cin >> n;
	for (ll i = 0; i < n; ++i)
	{
		cin >> t[i];
		sum += t[i];
	}

	ll diff = getDiff();

	//cout << diff << " diff \n";

	cout << (sum+diff)/2 /*<< " " << (sum-diff)/2 << "\n"*/;
		
}
