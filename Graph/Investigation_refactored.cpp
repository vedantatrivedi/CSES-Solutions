#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mxN = 1e5, M =1e9 + 7;
bool vis[mxN];
vector<int> adj[mxN]; // stores only all shortest routes to nth node
int n,m,dp[mxN]; 
ll d[mxN]; // shortest dist to every node from src obtained using dijkstra
vector<ar<ll,2>> adj2[mxN]; // Adjacency List for dijkstra

void dfs(int u){
	dp[u] = (u==n-1?1:0);
	vis[u] = 1;
	for(int v : adj[u]){
		if(!vis[v]){
			dfs(v);
		}
		dp[u] = (dp[u] + dp[v])%M; // v -> destination , u->src 
	}
}

void dfs2(int u){
	dp[u] = (u==n-1?1:1e9);
	vis[u] = 1;
	for(int v : adj[u]){
		if(!vis[v]){
			dfs2(v);
		}
		if( dp[v]+1< dp[u] ){
			dp[u] = dp[v] + 1;
		}
	}
}

void dfs3(int u){
	// cout << "\n " << u << "i\n";
	dp[u] = (u==n-1?1:-1e9);
	vis[u] = 1;
	for(int v : adj[u]){
		if(!vis[v]){
			dfs3(v);
		}
		if( dp[v]+1> dp[u] ){
			dp[u] = dp[v] + 1;
		}
	}
}

int main(){
	
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		ll a,b,c;
		cin >> a >> b >> c; --a; --b;
		adj2[a].push_back({c,b});
	}

	priority_queue< ar<ll,2> , vector< ar<ll,2> > , greater< ar<ll,2> > > pq;

	pq.push({0,0});
	memset(d,0x3f,sizeof(d));
	d[0] = 0;
	while( pq.size() ){
		ar<ll,2> u;
		u = pq.top();
		pq.pop();
		if( u[0]>d[u[1]] )
			continue;
		for( ar<ll,2> v : adj2[u[1]] ){
			if( d[v[1]]> d[u[1]] + v[0] ){
				d[v[1]] = d[u[1]] + v[0];
				pq.push({d[v[1]], v[1]});
			}
		}
	}

	cout << d[n-1] << " "; // output shortest distance to reach nth node

	for (int i = 0; i < n; ++i)
	{
		for( ar<ll,2> j : adj2[i] ){
			if( d[i]+j[0] == d[j[1]] ) // if shortest dist till source node + edge weight = shortest dist till dest node ( we are just storing all edges responsiblr for shortest paths till j[i]th node )
				adj[i].push_back(j[1]);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if(!vis[i]){
			dfs(i);
		}
	}

	cout  << dp[0]; // total number of shortest routes

	memset(vis,0,n);
	for (int i = 0; i < n; ++i)
	{
		if(!vis[i]){
			dfs2(i);
		}
	}
	cout << " " << dp[0]-1;
	memset(vis,0,n);
	for (int i = 0; i < n; ++i)
	{
		if(!vis[i]){
			dfs3(i);
		}
	}
	cout << " " << dp[0]-1;

	return 0;
}
