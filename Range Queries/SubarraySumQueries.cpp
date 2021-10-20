// link :https://cp-algorithms.com/data_structures/segment_tree.html#toc-tgt-3
// Heading -> Finding subsegments with the maximal sum in CP Algorithms
#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int mxN = 2e5;
int n,q;
ll x[mxN];

struct node{
	ll s,mxl,mxr,mx;
}st[1<<19];

/*
void app(int i, ll x, int l2, int r2){ // app -> means apply
	st[i].mn+=x;
	st[i].s+= x*(r2-l2+1);
	st[i].lz += x;
}

void psh(int i, int l2, int m2, int r2){
	app(2*i, st[i].lz , l2, m2);
	app(2*i+1, st[i].lz, m2+1,r2);
	st[i].lz = 0;
}
*/

void upd(int l1 /* l1 -> position of x[i] in array */, int x, int i=1, int l2=0, int r2=n-1){ // similar to inserting in a binary search tree
	if(l2==r2){ // leaf node
		// st[i].mn = x;
		st[i].s = x;
		st[i].mx = x;
		st[i].mxl = st[i].mxr = x;
		return ;
	}
	int m2 =(l2+r2)/2;
	// psh(i,l2,m2,r2);
	if(l1<=m2){
		upd(l1,x,2*i,l2,m2);
	}
	else{
		upd(l1,x,2*i+1,m2+1,r2);
	}
	/*
	struct data {
    int sum, pref, suff, ans;
	};

	data combine(data l, data r) {
	    data res;
	    res.sum = l.sum + r.sum;
	    res.pref = max(l.pref, l.sum + r.pref);
	    res.suff = max(r.suff, r.sum + l.suff);
	    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
	    return res;
	}
	*/
	st[i].mx = max({st[2*i].mx,st[2*i+1].mx,st[2*i].mxr+st[2*i+1].mxl});
	st[i].mxl = max({st[2*i].mxl,st[2*i].s+st[2*i+1].mxl}); // mxl -> prefix sum
	st[i].mxr = max({st[2*i+1].mxr,st[2*i+1].s+st[2*i].mxr}); // mxr -> suffix sum
	st[i].s = st[2*i].s + st[2*i+1].s;
}

/*
void upd2(int l1, int r1, ll x, int i=1, int l2=0, int r2=n-1){
	if(l1 <= l2 && r2<=r1){
		app(i,x, l2, r2);
		return ;
	}
	int m2 = (l2+r2)/2;
	psh(i,l2,m2,r2);
	if( l1<=m2 ){
		upd2(l1, r1, x, 2*i, l2, m2);
	}
	if( m2<r1 ){
		upd2(l1, r1, x, 2*i+1, m2+1, r2);
	}
	st[i].mn = min(st[2*i].mn,st[2*i+1].mn);
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
*/

int main(){
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i], upd(i,x[i]);
	}
	while(q--){
		int k;
		cin >> k, --k;
		cin >> x[k];
		upd(k,x[k]);
		cout << max(st[1].mx,0ll) << "\n" ;
	}
	return 0;
}
