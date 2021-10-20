#include <bits/stdc++.h>
using namespace std;
#define ar array

const int mxN = 2e5;
int n,d[mxN],ans[mxN]; // d means -> depth
vector<int> adj[mxN];

void dfs(int u=0, int p=-1){
	for(int v : adj[u]){
		if(v==p) continue; // avoid backward edge to parent
		
		dfs(v,u);
		// ans = max(d[u]+d[v]+1,ans);
		d[u] = max(d[u],d[v]+1);
	}
}

void dfs2(int u=0, int p=-1, int pd=0){ // p -> parent , pd -> max parent depth + 1
	ans[u]=max(d[u],pd);
	vector<ar<int,2>> w {{pd,-1}};
	for(int v : adj[u]){
		if(v==p) continue; // avoid backward edge to parent
		w.push_back({d[v]+1,v}); // push depth of parent from all it's children
	}
	w.push_back({0,-1});
	sort(w.begin(),w.end(), greater<ar<int,2>> ()); // descending order
	for(int v : adj[u]){
		if(v==p) continue; // avoid backward edge to parent
		dfs2(v,u,w[0][1]==v?w[1][0]+1:w[0][0]+1);
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
	dfs2();
	for(int i=0;i<n;++i){
		cout << ans[i] << " ";
	}
}
