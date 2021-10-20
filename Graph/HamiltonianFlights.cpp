// link : https://www.hackerearth.com/practice/algorithms/graphs/hamiltonian-path/tutorial/
#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mxN = 22, M = 1e9 + 7;
int n,m;
ll dp[1<<mxN][mxN]; // dp[ visited cities ][ last city ]
ll adj[mxN][mxN];

int main(){
	cin >> n >> m;
	for (int i = 0,a,b; i < m; ++i)
	{
		cin >> a >> b ,--a,--b;
		++adj[a][b];  // a-> src , b-> dest
	}
	dp[1][0] =1; // analogus to dp[ pow(2,0) ][0] = 1 -> there is a path that visits 0 th vertex and ends at 0th vertex
	for (ll i = 2; i<1<<n; ++i) // possible subsets
	{
		
		if(i!=(1<<n)-1&&((i>>(n-1))&1))continue;
		
		for (int j = 0; j < n; ++j) // all cities
		{
			if( i>>j&1 ){ // checking if jth city is in the subset
				int i2 = i^(1<<j); // remove j from subset
				for (int k = 0; k < n; ++k) // previous cities
				{
					if( i2>>k&1&&adj[k][j] ){
						dp[i][j]+=adj[k][j]*dp[i2][k];
					}
				}
				dp[i][j]%=M;
			}
		}
	}
	cout << dp[(1<<n)-1][n-1];
	return 0;
}


// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define MOD 1000000007
// vector<int>adj[22];
// ll dp[1100000][22];
// int n;
// ll F(int mask, int i)
// {
//     mask = mask ^ (1 << i);
//     if (mask == 0 && i == n - 1)
//         return 1;
//     if (i == n - 1)
//         return 0;
//     if (dp[mask][i] != - 1)
//         return dp[mask][i];
//     dp[mask][i] = 0;
//     for (auto j : adj[i])
//     {
//         if ((mask & (1 << j)))
//             dp[mask][i] = (dp[mask][i] + F(mask, j)) % MOD;
//     }
//     return dp[mask][i];
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     int m; cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int a, b; cin >> a >> b; a--; b--;
//         adj[a].push_back(b);
//     }
//     memset(dp, -1, sizeof(dp));
//     cout << F((1 << n) - 1, 0);
//     return 0;
// }
