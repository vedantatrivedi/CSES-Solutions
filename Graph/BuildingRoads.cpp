#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mxN = 1e5;
int n,m;
vector<int> adj[mxN], ans;
bool vis[mxN];

void dfs(int u){
	vis[u] = 1;
	for (int i = 0; i < adj[u].size(); ++i)
	{
		if(!vis[adj[u][i]])
			dfs(adj[u][i]);
	}
}
 
int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0,a,b; i < m; ++i)
	{
		cin >> a >> b; --a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < n; ++i)
	{
		if(!vis[i]){
			ans.push_back(i);
			dfs(i);
		}
	}

	cout << ans.size() - 1 << "\n";
	for (int i = 1; i < ans.size(); ++i)
	{
		cout << ans[0] + 1 << " " << ans[i] + 1 << "\n"; 
	}

	return 0;
}
