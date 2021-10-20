#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mxN = 1e5;
bool vis[mxN];
vector<int> adj[mxN],ans;
int n,m,p[mxN]; // p to store parents

void dfs(int u, int pu = -1){
	vis[u] = 1;
	p[u] = pu;
	for( auto v : adj[u] ){
		if( v == pu ) // we dont want self loop in ans
		{
			continue;
		}
		if( vis[v] ){ // if vis[v] = 1 -> means we found a cycle
			int u2 = u;
			while(u^v){ // while u and v are different backtrack
				ans.push_back(u);
				u = p[u];
			}
			ans.push_back(v);
			ans.push_back(u2);
			cout << ans.size() << "\n";
			for(int a : ans){
				cout << a+1 << " ";
			}
			exit(0);
		}else
			dfs(v,u);
	}
}

int main(){
	
	cin >> n >> m;
	for (int i = 0,a,b; i < m; ++i)
	{
		cin >> a >> b; --a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	memset(vis,0,n*sizeof(vis[0]));

	for (int i = 0; i < n; ++i)
	{
		if(!vis[i]){
			dfs(i,0);
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}