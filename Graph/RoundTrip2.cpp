#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mxN = 1e5;
bool vis[mxN],act[mxN];
vector<int> adj[mxN];
int n,m,p[mxN]; // p to store parents

void dfs(int u){
	vis[u] = 1;
	act[u] = 1;
	for( auto v : adj[u] ){
		if( act[v] ){ 
			vector<int> ans = {u};
			while(u^v){ // while we have not reached the same city from where we started
				u=p[u];
				ans.push_back(u);
			}
			ans.push_back(ans[0]);
			reverse(ans.begin(),ans.end());
			cout << ans.size() << "\n";
			for(int a : ans)
				cout << a+1 << " ";
			exit(0);
		}else{
			if(!vis[v]){
				p[v] = u;
				dfs(v);
			}
		}
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

	cout << "IMPOSSIBLE";

	return 0;
}
// DFS and logic to get directed cycle