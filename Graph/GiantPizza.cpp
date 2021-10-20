// https://codeforces.com/blog/entry/16205?
#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mxN = 2e5;
int n,m, who[mxN];
vector<int> adj[mxN], adj2[mxN], st, co; // adj2 contains reversed edges
bool vis[mxN];
char ans[mxN];

void dfs1(int u){
	vis[u] = 1;
	for(int v : adj[u]){ // v -> child , u-> parent
		if(!vis[v])
			dfs1(v);
	}
	st.push_back(u); 
}

void dfs2(int u, int rt){
	vis[u]=0;
	who[u] = rt;
	for(int v : adj2[u]){ // v -> parent , u -> child i.e reverse
		if(vis[v]){
			dfs2(v,rt);
		}
	}
	co.push_back(u);
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		char c1,c2;
		int u1,u2;
		cin >> c1 >> u1 >> c2 >> u2 ; --u1,--u2;
		u1*=2; 
		u2*=2;
		if(c1=='-'){ 
			u1^=1;
		}
		if(c2=='-'){ 
			u2^=1;
		}
		adj[u1^1].push_back(u2); //      here ^=1 means false else true
		adj[u2^1].push_back(u1); 

	}
	for (int i = 0; i < 2*m; ++i)
	{
		for( int j : adj[i] ){
			adj2[j].push_back(i);
		}
	}
	for (int i = 0; i < 2*m; ++i)
	{
		if(!vis[i]){
			dfs1(i);
		}
	}

	for (int i = 2*m-1; ~i; --i)
	{
		if(vis[st[i]]){
			dfs2(st[i],i);
			co.clear();
		}
	}
	for (int i = 0; i < m; ++i)
	{
		if( who[2*i]==who[2*i+1] ){ // f is not satisfiable if both ¬xi and xi are in the same SCC
			cout << "IMPOSSIBLE";
			return 0;
		}
		// cout << who[2*i] << " " << who[2*i+1] << endl;
		ans[i] = who[2*i]<who[2*i+1]?'+':'-';
	}
	for (int i = 0; i < m; ++i)
	{
		cout << ans[i] << " ";
	}

	return 0;
}
