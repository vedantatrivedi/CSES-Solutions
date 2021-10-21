// link : https://www.youtube.com/watch?v=jpIeCsX4oNo
#include <bits/stdc++.h>
using namespace std::chrono; 
#define ll long long
#define ar array
using namespace std;

const int mxN = 1e5;

vector<int> adjList[mxN];
int n,m;

int main(){

	// Get starting timepoint 
    auto start = high_resolution_clock::now(); 
	
	cin >> n >> m;
	vector<int> incoming(n,0);
	vector<int> p(n,-1); // -1 -> ith node is parent of itself
	vector<int> LPT(n,0);
	for (int i = 0; i < m; ++i)
	{
		int a,b;
		cin >> a >> b; --a; --b;
		adjList[a].push_back(b);
		incoming[b]++;
	}

	queue<int> q;
	int i;
	//for(i=0;i<incoming.size();++i) if(incoming[i]==0) q.push(i);
	q.push(0);
	while(!q.empty())
    {
        int c = q.front(); q.pop();
        // topologicalOrder.push_back(c);
        for(auto&u:adjList[c]){
        	// cout << c << " " << u ;
            // if(--incoming[u]==0) q.push(u);
            q.push(u);
            // LPT[u] = max(LPT[u],LPT[c]+1)
            if( LPT[u] < LPT[c]+1 ){
            	LPT[u] = LPT[c]+1;
            	p[u] = c;
            }
        }
    }
    // cout << "parents - \n";
    // for (int i = 0; i < n; ++i)
    // {
    // 	cout << p[i]+1 << " ";
    // }

    if( p[n-1]!=-1 ){
    	vector<int> ans; ans.push_back(n);
    
	    int cur = n-1;
	    while(cur!=0){
	    	if(p[cur]+1 == 0) goto here;
	    	ans.push_back(p[cur]+1);
	    	// cout << p[cur] << " ";
	    	cur = p[cur];
	    }

	    reverse(ans.begin(),ans.end());

	    cout << ans.size() << "\n";
	    for (int i = 0; i < ans.size(); ++i)
	    {
	    	cout << ans[i] << " ";
	    }
    }else{
    	here:
    	cout << "IMPOSSIBLE";
    }

    // Get ending timepoint 
    auto stop = high_resolution_clock::now(); 
  
    // Get duration. Substart timepoints to  
    // get durarion. To cast it to proper unit 
    // use duration cast method 
    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "\nTime taken by function: "
         << duration.count() << " microseconds" << endl; 

    //cout << "\nLPT[n-1] " << LPT[n-1]; 
  
	return 0;
}
