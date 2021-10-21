#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mxN = 1e5;
int n,m;

vector<ar<ll,2>> adj[mxN];
ll d[mxN];

int main(){
	
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a,b,c;
		cin >> a >> b >> c; --a; --b;
		adj[a].push_back({c,b}); // {dist,city}
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
		for( ar<ll,2> v : adj[u[1]] ){
			if( d[v[1]]> d[u[1]] + v[0] ){
				d[v[1]] = d[u[1]] + v[0];
				pq.push({d[v[1]], v[1]});
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << d[i] << " ";
	}

	return 0;
}
