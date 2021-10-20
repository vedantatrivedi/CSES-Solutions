#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int mxN = 2e5;
int n,q;
ll x[mxN];

struct node{
	ll s,mn,lz; // s -> means tot distinct values in segment
}st[1<<19];


void app(int i, ll x, int l2, int r2){ // app -> means apply
	// st[i].mn+=x;
	st[i].s+= x*(r2-l2+1);
	st[i].lz += x;
}

void psh(int i, int l2, int m2, int r2){
	app(2*i, st[i].lz , l2, m2);
	app(2*i+1, st[i].lz, m2+1,r2);
	st[i].lz = 0;
}


void upd(int l1 /* l1 -> position of x[i] in array */, int x, int i=1, int l2=0, int r2=n-1){ // similar to inserting in a binary search tree
	if(l2==r2){ // leaf node
		// st[i].mn = x;
		st[i].s = x;
		return ;
	}
	int m2 =(l2+r2)/2;
	psh(i,l2,m2,r2);
	if(l1<=m2){
		upd(l1,x,2*i,l2,m2);
	}
	else{
		upd(l1,x,2*i+1,m2+1,r2);
	}
	
	// st[i].mn = min(st[2*i].mn, st[2*i+1].mn);
	st[i].s = st[2*i].s + st[2*i+1].s;
}

ll qry(int l1,int r1, int i=1, int l2=0, int r2=n-1){
	if(l1<=l2 && r2<=r1){
		return st[i].s;
	}
	int m2 = (l2+r2)/2;
	psh(i,l2,m2,r2);
	// return min( l1<=m2? qry(l1,r1,2*i,l2,m2):(int)1e9 , m2<r1? qry(l1,r1,2*i+1,m2+1,r2) : (int)1e9  );
	return ( l1<=m2? qry(l1,r1,2*i,l2,m2):0 ) + ( m2<r1? qry(l1,r1,2*i+1,m2+1,r2) :0 );
}

vector< ar<int,2> > ta[mxN]; // stores left bound and index
int ans[mxN];

int main(){
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i];
	}
	for(int i=0; i<q; ++i){
		int a,b;
		cin >> a >> b, --a, --b;
		ta[b].push_back({a,i});
	}
	map<int,int> mp; // mp will store the Idx of last occurance of number
	for(int i=0; i<n; ++i){
		upd(i,1); // update current index to one since we found one distinct value
		if(mp.find(x[i])!=mp.end()){
			upd(mp[x[i]],0);
		}
		mp[x[i]] = i; // update last occurance Idx
		for( ar<int,2> a : ta[i] ){
			ans[a[1]] = qry(a[0],i);
		}
	}
	for(int i=0; i<q; ++i){
		cout << ans[i] << "\n";
	}
	return 0;
}
