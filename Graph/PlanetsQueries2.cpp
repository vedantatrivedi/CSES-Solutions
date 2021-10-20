#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mxN = 2e5;
int n,q,dt,t[mxN],d[mxN],rt[mxN],rp[mxN],cr[mxN],ds[mxN],de[mxN],cs[mxN]; // rt ->root of the node, d->depth of the node, cr-> cycle route, cs -> cycle sizes, rp-> root position of node, t-> teleported planet
bool vis[mxN];
vector<int> adj[mxN],cyc;

void dfs1(int u){
	ds[u]= dt++;
	for(int v : adj[u]){
		if(rt[v]^v  ){
			d[v] = d[u] + 1; // depth[src] = depth[child] + 1
			rt[v] = rt[u];   // root[parent] = root[child] ( analogus to DSU collapsing find )
			cr[v] = cr[u];   // cycle route [parent] = cycle route [child] ( analogus to DSU collapsing find )
			dfs1(v);
		}
	}
	de[u] = dt;
}

int main(){

	cin >> n >>  q;
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << d[i] << " ";
	// }
	// d[mxN] is by default assigned to 0 on all indices
	// cout << "d\n";
	for (int i = 0; i < n; ++i)
	{
		cin >> t[i]; --t[i];
		adj[t[i]].push_back(i); // i is incoming edge to t[i] , so we are storing parents in adj
	}
	memset(rt,-1,4*n);
	for (int i = 0; i < n; ++i)
	{
		// cout << rt[i] << " " << (bool)(~rt[i]) << "\n";
		if(~rt[i]) continue;  // to avoid nodes which already have a root
		int u = i;
		while(!vis[u]){ // mark full all cycle/non-cycle nodes as visited
			vis[u] = 1;
			u = t[u];  // t[u]-> child of u
		}
		// after the while loop , now varible "u" is at begining of the cycle 
		while( !cyc.size() || u^cyc[0] ){ // if cyc is empty or we have not reached end of cyc( u and cyc[0] are different )
			rp[u] = cyc.size();
			cyc.push_back(u); // storing the cycle
			rt[u] = u;
			cr[u] = i;  // imp as we store node which might not be in cycle but leads to cycle if we traverse it
			u = t[u]; // t[u]-> child of u
		}
		for(int ci : cyc){
			dt = 0;
			dfs1(ci), cs[ci]=cyc.size(); // storing "cycle size" for every node in cyc
		}
		cyc.clear();
	}
	while(q--){
		int a,b;
		cin >> a >> b; --a,--b;
		int ans = -1;
		if( cr[a]==cr[b] ){
			if( rt[b]==b ){
				ans=d[a];
				a = rt[a];
				ans += (rp[b] - rp[a] + cs[a])% cs[a];
			}else{
				if( rt[a]==rt[b] && ds[b]<= ds[a] && ds[a]<de[b] ){
					ans = d[a]-d[b];
				}
			}
		}
	
		cout << ans << "\n";
	}
}
