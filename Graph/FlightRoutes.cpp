#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mxN = 1e5;
int n,m,k;

vector<ar<ll,2>> adj[mxN];
vector<ll> d[mxN];

int main(){
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i)
	{
		int a,b,c;
		cin >> a >> b >> c; --a; --b;
		adj[a].push_back({c,b}); // {dist,city}
	}

	priority_queue< ar<ll,2> , vector< ar<ll,2> > , greater< ar<ll,2> > > pq;  // pops in ascending order of distances

	pq.push({0,0});
	while( pq.size() ){
		ar<ll,2> u;
		u = pq.top();
		pq.pop();
		if( d[u[1]].size()>=k ){
			// cout <<  "continue" << u[0] << " " << u[1] << "\n";
			continue;
		}
		// cout <<  u[0] << " " << u[1] << "\n";
		d[u[1]].push_back(u[0]);
		for( ar<ll,2> v : adj[u[1]] ){
			pq.push({u[0]+v[0], v[1]});
			// cout <<  "for loop " << u[0]+v[0] << " " << v[1] << "\n";

		}
	}

	for (int i = 0; i < k; ++i)
		cout << d[n-1][i] << " ";
	
	return 0;
}
