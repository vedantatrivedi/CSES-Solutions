#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mxN = 1e5, mxM=2e5;
int n,m,eu[mxM],ev[mxM];
vector<int> adj[mxN],ans;
bool used[mxM];

void dfs(int u=0){
	while( adj[u].size() ){
		int e = adj[u].back();
		adj[u].pop_back();
		if( used[e] )
			continue;
		used[e] = 1;
		// cout << e << " " << eu[e] << " " << ev[e] << " " << u << " " << ( eu[e]^ev[e]^u ) << "\n";
		dfs(eu[e]^ev[e]^u); // going to node that is not visited since it is undirected graph
		ans.push_back(u);
	}
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < m; ++i) // m edges
	{
		cin >> eu[i] >> ev[i] ,--eu[i],--ev[i];
		adj[eu[i]].push_back(i); // city number 1 is stored in eu[i] , i is edge number
		adj[ev[i]].push_back(i); // city number 2 is stored in ev[i] , i is edge number
	}
	// cout << "e " << "eu[e] " << "ev[u] " << "u " << "eu[e]^ev[e]^u \n";
	for (int i = 0; i < n; ++i)
	{
		if(adj[i].size()&1){ // if any edge was not poped 
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	ans.push_back(0);
	dfs();
	if(ans.size()^m+1){ // 
		cout << "IMPOSSIBLE";
	}else{
		for (int a : ans)
		{
			cout << a+1 << " ";
		}
	}
	return 0;
}
