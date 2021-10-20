// link : https://cp-algorithms.com/graph/bellman_ford.html
#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int n,m;
vector<ar<int,3>> edges;

int main(){

	cin >> n >> m;
	
	vector<ll> d(n,0);
	vector<int> p(n, -1);
	for (int i = 0; i < m; ++i)
	{
		int a,b,c;
		cin >> a >> b >> c; --a,--b;
		edges.push_back({a,b,c}); // directed graph
	}

	// Bellman Ford
	d[1] = 0;
	int x = -1;
	for (int i = 0; i < n-1; ++i)
	{
		for( ar<int,3> e : edges ){
			if( d[e[1]] > d[e[0]] + e[2] ){
				d[e[1]] = max ((ll)-1e15, d[e[0]] + e[2] );
				p[e[1]] = e[0];
			}
		}
	}

	for( ar<int,3> e : edges ){
		if( d[e[1]] > d[e[0]] + e[2] ){
			d[e[1]] = max ((ll)-1e15, d[e[0]] + e[2] );
			p[e[1]] = e[0];
			x = e[0];
		}
	}

	if (x == -1)
        cout << "NO" ;
    else{
    	int y = x;
        for (int i=0; i<n; ++i)
            y = p[y];

        vector<int> path;
        for (int cur=y; ; cur=p[cur])
        {
            path.push_back (cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse (path.begin(), path.end());
        cout << "YES\n" ;
        for (size_t i=0; i<path.size(); ++i)
            cout << path[i]+1 << ' ';
    }

	return 0;
}