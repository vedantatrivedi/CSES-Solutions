#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 2500;
int n,m;


// ll d[mxN] = {(ll)-1e15}; CAUTION THIS METHOD GIVES ALL VALUES TO ARRAY AS ZERO FOR SOME REASON!!

int main(){
	
	cin >> n >> m;
	vector<vector<int>>edges;
	while(m--)
	{
		int a,b,c;
		cin >> a >> b >> c; //--a; --b;
		edges.push_back({a,b,c});  // directional edges
	}

	vector<ll>d(n + 1, -1e15);
	d[1] = 0; // initial score is zero
	// cout << d[3] << "\n";
	for(int i=1; i<n; ++i){
		for( auto e : edges ){
			if( (d[e[0]] != -1e15) && d[e[0]] + e[2]>d[e[1]] ){ // (d[e[0]] != -1e15) ensures -> 1)Other paths to nth node which do not begin from 1st node are excluded
				// cout << d[e[1]] << " " << d[e[0]] << " " << e[0] << " " << e[1] << "\n";
				d[e[1]] = d[e[0]] + e[2] ;
				// cout << d[e[1]] << " " << d[e[0]] << " " << e[0] << " " << e[1] << "\n";
			}
		}
	}
	//cout << "HI\n";
	for(int i=1; i<n; ++i){
		for( auto e : edges ){
			if( (d[e[0]] != -1e15) && d[e[0]] + e[2]>d[e[1]] ) // if score still increases on applying Bellman Ford again -> positive weight cycle is there till e[1] // (d[e[0]] != -1e15) ensures  -> 1)Other paths to nth node which do not begin from 1st node are excluded . other paths to nth node which have a cycle and dont begin with 1st node should not make nth node = 1e15
			{	// cout << d[e[1]] << " " << d[e[0]] << " " << e[0] << " " << e[1] << "\n";
				d[e[1]] = 1e15;
				// cout << d[e[1]] << " " << d[e[0]] << " " << e[0] << " " << e[1] << "\n";
			}
		}		
	}
	if( d[n]==1e15 ){
		cout << -1;
	}else{
		cout << d[n];
	}

	return 0;
}
