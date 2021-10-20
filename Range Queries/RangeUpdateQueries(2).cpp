#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int mxN = 2e5;
int n,q;
ll x[mxN];

struct node{
	ll s,lz;
}st[1<<19]; // pow(2,19) = 5 x pow(10,5) and child of 2 x pow(10,5) = 4 x pow(10,5)

void app(int i, ll x, int l2, int r2){ // app -> means apply
	st[i].s+= x*(r2-l2+1);
	st[i].lz += x;
}

void psh(int i, int l2, int m2, int r2){
	app(2*i  , st[i].lz, l2  , m2); // app parents lz
	app(2*i+1, st[i].lz, m2+1, r2);
	st[i].lz = 0; // make parents lz to zero 
}

void upd(int l1 /* l1 -> position of x[i] in array */, int x, int i=1, int l2=0, int r2=n-1){ // similar to inserting in a binary search tree
	if(l2==r2){ // leaf node
		st[i].s = x;
		return ;
	}
	int m2 =(l2+r2)/2;
	if(l1<=m2){
		upd(l1,x,2*i,l2,m2);
	}
	else{
		upd(l1,x,2*i+1,m2+1,r2);
	}
}

void upd2(int l1, int r1, ll x, int i=1, int l2=0, int r2=n-1){
	if(l1<=l2 && r2<=r1){ // check for overlap  {l1       {l2          r2}         r1}
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
	st[i].s = st[2*i].s + st[2*i+1].s;
}

ll qry(int l1,int r1, int i=1, int l2=0, int r2=n-1){
	if(l1<=l2 && r2<=r1){ // check for overlap  {l1       {l2          r2}         r1}
		return st[i].s;
	}
	int m2 = (l2+r2)/2;
	psh(i,l2,m2,r2);
	return ( l1<=m2? qry(l1,r1,2*i,l2,m2):0 ) + ( m2<r1? qry(l1,r1,2*i+1,m2+1,r2) :0 );
}

int main(){
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i], upd(i,x[i]);
	}
	while(q--){
		int qt;
		cin >> qt;
		if(qt==1){
			int a,b,u;
			cin >> a >> b >> u , --a,--b;
			upd2(a,b,u);
		}else{
			int k;
			cin >> k, --k;
			cout << qry(k,k) << "\n";
		}
	}
	return 0;
}
