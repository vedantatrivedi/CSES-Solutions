#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mxN = 1e5,mxM = 2e5;
int n,m,p[mxN];
ar<int,3> e[mxM]; // { c, a, b } -> correct , a->src , b-> dhild, c-> cost/weight
ll ans;

int find( int x ){
	return x^p[x]?p[x]=find(p[x]):x;
}

bool join (int x, int y){
	if( (x=find(x)) == (y=find(y)) )
		return 0;
	p[x] = y;
	return 1;
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> e[i][1] >> e[i][2] >> e[i][0];
		--e[i][1] , --e[i][2];
	}
	sort(e,e+m); // sort wrt cost
	iota(p,p+n,0);
	int a1 = 0; // roads to be repaired
	ll a2 = 0; // minimum cost of reparation
	for (int i = 0; i < m; ++i)
	{
		if( join(e[i][1],e[i][2]) ){
			++a1, a2+=e[i][0];
		}
	}
	if( a1<n-1 )
		cout << "IMPOSSIBLE";
	else{
		cout << a2;
	}

	return 0;
}