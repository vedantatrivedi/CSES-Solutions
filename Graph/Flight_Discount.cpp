#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mxN = 1e5;
int n,m;
vector<ar<ll,2>> adj1[mxN], adj2[mxN];
ll d1[mxN],d2[mxN]; // min dist to reach city i (present at ith index) from src city

void dij(int u, vector<ar<ll,2>> adj[mxN], ll d[mxN]){
	memset(d,0x3f,sizeof(d1));  // NOTE -> sizeof(d1) is IMP and memset(d,0x3f,sizeof(d)) is wrong
	d[u] = 0;
	priority_queue< ar<ll,2> , vector<ar<ll,2>> , greater<ar<ll,2>> > pq;  // it contains {dist to reach city A from node B, city A}
	pq.push({0,u});
	while(pq.size()){
		ar<ll,2> u = pq.top(); pq.pop();
		// link : https://cp-algorithms.com/graph/dijkstra_sparse.html
		if( u[0]>d[u[1]] ) // some priority queue reason -> We simply don't delete the old pair from the pqueue. As a result a vertex can appear multiple times with different distance in the pqueue at the same time. Among these pairs we are only interested in the pairs where the first element is equal to the corresponding value in d[], all the other pairs are old. Therefore we need to make a small modification: at the beginning of each iteration, after extracting the next pair, we check if it is an important pair or if it is already an old and handled pair.
			continue;
		for( ar<ll,2> v : adj[u[1]] ){
			if( d[v[1]] > u[0] + v[0]  ){
				d[v[1]] = u[0] + v[0];
				pq.push({d[v[1]],v[1]});
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		ll a,b,c;
		cin >> a >> b >> c; --a,--b;
		adj1[a].push_back({c,b});
		adj2[b].push_back({c,a}); // {dist,city}
	}
	dij(0, adj1, d1);
	dij(n-1, adj2, d2);
	ll ans = 1e18;
	for (int i = 0; i < n; ++i)
	{
		for( ar<ll,2> v : adj1[i] ) // go throught every edge
			ans = min(ans, v[0]/2 + d1[i] + d2[v[1]]);
	}
	cout << ans;
	return 0;
}