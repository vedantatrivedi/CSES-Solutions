#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mxN = 1<<14, mxM=1<<15;
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
		ans.push_back(e);
	}
}

int main(){
	cin >> n ;
	for (int i = 0; i < 1<<n; ++i) 
	{
	
		eu[i]=i/2;
		ev[i] = i&((1<<n-1)-1);
		adj[eu[i]].push_back(i);
		// adj[ev[i]].push_back(i); 
	}
	// cout << "e " << "eu[e] " << "ev[u] " << "u " << "eu[e]^ev[e]^u \n";
	for (int i = 0; i < n; ++i)
	{
		if(adj[i].size()&1){ // if any edge was not poped 
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	
	dfs();
	for (int a : ans)
	{
		cout << a%2;
	}
	for (int i = 0; i < n-1; ++i)
	{
		cout << 0;
	}
	
	
	
	return 0;
}
