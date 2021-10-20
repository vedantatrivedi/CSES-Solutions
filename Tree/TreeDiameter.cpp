#include <bits/stdc++.h>
using namespace std;
#define ar array

const int mxN = 2e5;
int n,d[mxN],ans; // d means -> depth
vector<int> adj[mxN];

void dfs(int u=0, int p=-1){
	for(int v : adj[u]){
		if(v==p) continue; // avoid backward edge to parent
		
		dfs(v,u);
		ans = max(d[u]+d[v]+1,ans);
		d[u] = max(d[u],d[v]+1);
	}
}

int main(){
	cin >> n;
	for(int i=1;i<n;++i){
		int p,q;
		cin >> p >> q,--p,--q;
		adj[p].push_back(q);
		adj[q].push_back(p);
	}
	dfs();
	cout << ans;
}
