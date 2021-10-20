// RELATE IT TO PLANET QUERIES 2 CSES PROBLEMSET
#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mxN = 1e5,mxM = 2e5;
int n,m, who[mxN];
vector<int> adj[mxN], adj2[mxN], st, co; // adj2 contains reversed edges
bool vis[mxN];

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
	// cout << u << "\n";

}

int main(){
	cin >> n >> m;
	for (int i = 0,a,b; i < m; ++i)
	{
		cin >> a >> b, --a,--b;
		adj[a].push_back(b);
		adj2[b].push_back(a);
	}
	for (int i = 0; i < n; ++i)
	{
		if(!vis[i]){
			dfs1(i);
		}
	}
	// cout << "st\n";
	// for (int i = 0; i < st.size(); ++i)
	// {
	// 	cout << st[i]+1 << " ";
	// }
	// cout  << "\n";

	vector<int> ans;
	for (int i = n-1; ~i; --i)
	{
		if(vis[st[i]]){
			dfs2(st[i],st[i]);
			// cout << "co\n";
			// for (int i = 0; i < co.size(); ++i)
			// {
			// 	cout << co[i]+1 << " ";
			// }
			// cout  << "\n";
			// if( co.size()==n ){
			// 	cout << "YES";
			// 	return 0;
				
			// }else{
				// cout << " ans pb " << st[i]+1 << "\n";
				ans.push_back(st[i]);
			
			
		}
	}
	
	cout << ans.size() << "\n";
	map<int,int> mp;
	for (int i = 0; i < ans.size(); ++i)
	{
		mp[ans[i]] = i;
	}
	for (int i = 0; i < n; ++i)
	{
		cout << mp[who[i]]+1 << " ";
	}

	return 0;
}
