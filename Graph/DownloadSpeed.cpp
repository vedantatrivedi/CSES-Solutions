#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mxN = 500, mxM = 1e3;
int n,m,d[mxN],p[mxN];
vector<int> adj[mxN];

struct edge{
	int u,v,rev,cap; // rev -> reverse edge , cap -> capacity
}e[2*mxM];


int main(){
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a,b,c;
		cin >> a >> b >> c, --b,--a;
		e[2*i] = {a,b,2*i+1,c};
		e[2*i+1] = {b,a,2*i,0}; // reverse edge has 0 capacity
		adj[a].push_back(2*i);  // pushing edge number
		adj[b].push_back(2*i+1); // edge number of reverse edge =  edge number of forward edge + 1
	}
	ll f = 0; // f -> flow
	// BFS
	while(1){
		memset(d,0x3f,sizeof(d));
		d[0] = 0;
		queue<int> qu;
		qu.push(0);
		while( qu.size() ){
			int u = qu.front(); 
			qu.pop();
			for( int i : adj[u]){ // i -> edge 
				if( e[i].cap && d[e[i].v]>1e9 ){ // taking only forward edges as capacity for reverse edges is zero
					d[e[i].v] = d[u] + 1;
					p[e[i].v] = i;
					qu.push(e[i].v);
				}
			}
		}
		if(d[n-1]>1e9){
			break;
		}
		int mf=1e9, u =n-1; // mf -> minimum flow
		while(u){
			mf = min(mf,e[p[u]].cap );
			u = e[p[u]].u;
		}
		f+=mf;
		u = n-1;
		while(u){
			e[p[u]].cap-=mf; // reducing capacity of forward edges
			e[e[p[u]].rev].cap += mf; // increasing capacity of reverse edges
			u = e[p[u]].u;
		}
	}
	cout << f;
}
