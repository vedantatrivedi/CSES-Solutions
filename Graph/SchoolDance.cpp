#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mxN = 500;
int n,m,k,mt[mxN]; // mt -> means match
vector<int> adj[mxN];
bool vis[mxN];

bool dfs(int u){
	vis[u] = 1;
	for( int v1 : adj[u] ){
		if( mt[v1]<0 || !vis[mt[v1]] && dfs(mt[v1]) ){
			mt[v1] = u;
			return 1;
		}
	}
	return 0;
}


int main(){
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i)
	{
		int a,b;
		cin >> a >> b , --a , --b;
		adj[a].push_back(b);
	}
	int f = 0;
	memset(mt,-1,4*m);
	memset(vis,0,n);
	for(int i=0; i< n; ++i){
		memset(vis,0,n);
		f+=dfs(i);
	}
	cout << f << "\n";
	for (int i = 0; i < m; ++i)
	{
		if( ~mt[i] ){
			cout << mt[i]+1 << " " << i+1 << "\n";
		}
	}
}
