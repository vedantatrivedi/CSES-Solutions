#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mxN = 1e5, M =1e9 + 7;
bool vis[mxN],act[mxN];
vector<int> adj[mxN];
int n,m,p[mxN],dp[mxN]; // p to store parents
ll d[mxN]; // obtained using dijkstra
vector<ar<ll,2>> adj2[mxN];

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

void dfs2(int u){
	dp[u] = (u==n-1?1:1e9);
	vis[u] = 1;
	act[u] = 1;

	for(int v : adj[u]){
		if(act[v]){
			cout << "IMPOSSIBLE";
			exit(0);
		}else{
			if(!vis[v]){
				p[v] = u;
				dfs2(v);
			}
		}
		if( dp[v]+1< dp[u] ){
			p[u] = v; dp[u] = dp[v] + 1;
		}
		// dp[u] = (dp[u] + dp[v])%M;
	}
	
	act[u] = 0;
}

void dfs3(int u){
	dp[u] = (u==n-1?1:-1e9);
	vis[u] = 1;
	act[u] = 1;

	for(int v : adj[u]){
		if(act[v]){
			cout << "IMPOSSIBLE";
			exit(0);
		}else{
			if(!vis[v]){
				p[v] = u;
				dfs3(v);
			}
		}
		if( dp[v]+1> dp[u] ){
			p[u] = v; dp[u] = dp[v] + 1;
		}
		// dp[u] = (dp[u] + dp[v])%M;
	}
	
	act[u] = 0;
}

int main(){
	
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		ll a,b,c;
		cin >> a >> b >> c; --a; --b;
		adj2[a].push_back({c,b});
	}

	// memset(d,0x3f,sizeof(d));
	// d[0] = 0;
	// priority_queue< ar<ll,2> , vector<ar<ll,2>> , greater<ar<ll,2>> > pq;  // it contains {dist to reach city A from node B, city A}
	// pq.push({0,0});
	
	// while(pq.size()){
	// 	ar<ll,2> u = pq.top(); pq.pop();
	// 	// link : https://cp-algorithms.com/graph/dijkstra_sparse.html
	// 	if( u[0]>d[u[1]] ) // some priority queue reason -> We simply don't delete the old pair from the pqueue. As a result a vertex can appear multiple times with different distance in the pqueue at the same time. Among these pairs we are only interested in the pairs where the first element is equal to the corresponding value in d[], all the other pairs are old. Therefore we need to make a small modification: at the beginning of each iteration, after extracting the next pair, we check if it is an important pair or if it is already an old and handled pair.
	// 		continue;
	// 	for( ar<ll,2> v : adj2[u[1]] ){
	// 		if( d[v[1]] > u[0] + v[0]  ){
	// 			d[v[1]] = u[0] + v[0];
	// 			pq.push({d[v[1]],v[1]});
	// 		}
	// 	}
	// }

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

	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << d[i] << " ";
	// }
	// cout << "\n";
	cout << d[n-1] << " ";

	for (int i = 0; i < n; ++i)
	{
		for( ar<ll,2> j : adj2[i] ){
			if( d[i]+j[0] == d[j[1]] )
				adj[i].push_back(j[1]);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if(!vis[i]){
			dfs(i);
		}
	}

	cout  << dp[0];

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
