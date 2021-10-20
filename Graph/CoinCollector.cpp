#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mxN = 2e5;
int n,m, who[mxN];
vector<int> adj[mxN], adj2[mxN],adj3[mxN], st, co; // adj2 contains reversed edges
bool vis[mxN];
char ans[mxN];
ll x[mxN],y[mxN],dp[mxN];

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
	y[who[u]]+= x[u]; // add coins to rt 
	co.push_back(u);
}

void dfs3(int u){
	vis[u] = 1;
	for(int v : adj3[u]){
		if(!vis[v]){
			dfs3(v);
		}
		dp[u] = max(dp[u],dp[v]);
	}
	dp[u] += y[u];
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i];
	}
	for (int i = 0,a,b; i < m; ++i)
	{
		cin >> a >> b; --a,--b;
		adj[a].push_back(b);
	}
	for (int i = 0; i < n; ++i)
	{
		for( int j : adj[i] ){
			adj2[j].push_back(i);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if(!vis[i]){
			dfs1(i);
		}
	}

	for (int i = n-1; ~i; --i)
	{
		if(vis[st[i]]){
			dfs2(st[i],st[i]);
			co.clear();
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for( int j : adj[i] ){
			if(who[i]!=who[j]){
				adj3[who[i]].push_back(who[j]); // pushing other (strongly connected) components reachable from strongly connected componenets 
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if(who[i]==i && !vis[i]){
			dfs3(i);
			ans = max(dp[i],ans);
		}
	}
	cout << ans;

	return 0;
}
