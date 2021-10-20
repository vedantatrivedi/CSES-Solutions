#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mxN = 1e5,mxM = 2e5;
int n,m,p[mxN],s[mxN];
ar<int,3> e[mxM]; // { c, a, b } -> correct , a->src , b-> dhild, c-> cost/weight
ll ans;

int find( int x ){
	return x^p[x]?p[x]=find(p[x]):x;
}

bool join (int x, int y){
	if( (x=find(x)) == (y=find(y)) )
		return 0;
	p[x] = y;
	s[y]+=s[x];
	return 1;
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> e[i][1] >> e[i][2];
		--e[i][1] , --e[i][2];
	}
	
	iota(p,p+n,0);
	fill(s,s+n,1);
	int a1 = n, a2 = 1; 
	for (int i = 0; i < m; ++i)
	{
		if( join(e[i][1],e[i][2]) ){
			--a1, a2=max(a2,s[find(e[i][1])]);
		}
		cout << a1 << " " << a2 << "\n";
	}
	

	return 0;
}