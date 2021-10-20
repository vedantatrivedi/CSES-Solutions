#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mxN = 1e5, M =1e9 + 7;
bool vis[mxN],act[mxN];
vector<int> adj[mxN];
int n,m,p[mxN],dp[mxN]; // p to store parents

void dfs(int u){
	dp[u] = (u==n-1?1:0);
	vis[u] = 1;
	act[u] = 1;

	for(int v : adj[u]){
		if(act[v]){
			cout << "IMPOSSIBLE";
			exit(0);
		}else{
			if(!vis[v]){
				p[v] = u;
				dfs(v);
			}
		}
		dp[u] = (dp[u] + dp[v])%M;
	}
	
	act[u] = 0;
}

int main(){
	
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		ll a,b;
		cin >> a >> b; --a; --b;
		adj[a].push_back(b);
	}

	memset(vis,0,n*sizeof(vis[0]));

	for (int i = 0; i < n; ++i)
	{
		if(!vis[i]){
			dfs(i);
		}
	}

	cout << dp[0];

	return 0;
}
