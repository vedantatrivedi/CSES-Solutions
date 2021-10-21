#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <class T> using oset = tree<T, null_type, less<T> , rb_tree_tag , tree_order_statistics_node_update >; // red black tree is a self balancing Binary Search Tree

int n,q,p[200000];
oset<ar<int,2>> s;

int qry(int x){
	return s.order_of_key({x,0});
}

int main(){
	cin >> n >> q;
	for(int i=0; i<n; ++i){
		cin >> p[i];
		s.insert({p[i],i}); // Red Black Tree with respect to salary
	}
	for(int i=0; i<q; ++i){
		char qt;
		cin >> qt;
		if(qt=='!'){
			int k,x;
			cin >> k >> x , --k;
			s.erase({p[k],k});
			p[k]=x;
			s.insert({p[k],k});
		}else{
			int a,b;
			cin >> a >> b;
			cout << qry(b+1)-qry(a) << "\n";
		}
		
	}
	return 0;
}