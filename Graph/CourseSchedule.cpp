#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int n,m;

int main(){

	cin >> n >> m;
	vector<int> adjList[n]; // array of vectors
	vector<int> incoming(n,0);
	vector<int> topologicalOrder;
	for(int i=0; i<m; ++i){
		int a,b;
		cin >> a >> b; --a,--b;
		adjList[a].push_back(b);  // a is src, b is destination
		incoming[b]++;
	}
	queue<int> q;
	int i;
	for(i=0;i<incoming.size();++i) if(incoming[i]==0) q.push(i);

	while(!q.empty())
    {
        int c = q.front(); q.pop();
        topologicalOrder.push_back(c);
        for(auto&u:adjList[c]){
            if(--incoming[u]==0) q.push(u);
        }
    }

    if(topologicalOrder.size()!=n){
    	cout << "IMPOSSIBLE";
    }else{
    	for (i = 0; i < n; ++i)
	    {
	    	cout << topologicalOrder[i]+1 << " ";
	    }
    }

	return 0;
}