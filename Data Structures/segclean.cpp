#include<bits/stdc++.h>
using namespace std;

// 1 based indexing,sum-tree
vector <int> tree;
vector <int> lazy;

// Not required if ,starting with empty array
void build(){
	for(int i=tree.size()/2 - 1;i>0;i--)
		tree[i] = tree[2*i] + tree[2*i + 1];
}

int range_sum(int node,int start,int end,int l,int r){
	if(r<start || l > end )
		return 0 ;
	if(l<=start && end<=r)
		return tree[node];

	int mid = (start+end)/2;
	int left_sum = range_sum(2*node,start,mid,l,r);
	int right_sum = range_sum(2*node+1,mid+1,end,l,r);
	return left_sum + right_sum;

}

void range_update(int node,int start,int end,int l,int r,int x){
	cout << start << " " << end << endl;
	if(r<start || l > end )
		return ;
	if(start==end){
		tree[node]+=x;
		return;
	}

	int mid = (start+end)/2;
	range_update(2*node,start,mid,l,r,x);
	range_update(2*node+1,mid+1,end,l,r,x);
	tree[node] = tree[2*node] + tree[2*node+1];
}

void range_update_l(int node,int start,int end,int l,int r,int x){

	if(lazy[node]!=0){
		tree[node] += (end-start+1)*lazy[node];
		if(start!=end){
			lazy[node*2] += lazy[node];
			lazy[node*2 + 1] += lazy[node];
		}
		lazy[node]=0;
	}

	if(r<start || l > end )
		return ;
	if(l<=start && end<=r){
		tree[node]+= ((end-start+1)*x);
		if(start!=end){
			lazy[node*2] += x;
			lazy[node*2 + 1] += x;
		}
		return;
	}
	int mid = (start+end)/2;
	range_update_l(2*node,start,mid,l,r,x);
	range_update_l(2*node+1,mid+1,end,l,r,x);
	tree[node] = tree[2*node] + tree[2*node+1];

}

int range_sum_l(int node,int start,int end,int l,int r){

	if(lazy[node]!=0){
		tree[node] += (end-start+1)*lazy[node];
		if(start!=end){
			lazy[node*2] += lazy[node];
			lazy[node*2 + 1] += lazy[node];
		}
		lazy[node]=0;
	}

	if(r<start || l > end )
		return 0 ;
	if(l<=start && end<=r)
		return tree[node];

	int mid = (start+end)/2;
	int left_sum = range_sum_l(2*node,start,mid,l,r);
	int right_sum = range_sum_l(2*node+1,mid+1,end,l,r);
	return left_sum + right_sum;

}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int tree_size;
		if(pow(2, (int) log2(n))==n)
			tree_size = 2*n;
		else
			tree_size = 2 * pow(2,(int) log2(n)+1);
		
		lazy = tree = vector <int>(tree_size,0);

		// If taking input for array
		for(int i=0;i<n;i++)
			cin >> tree[tree_size/2 + i];

		build();
		for(auto it : tree)
			cout << it << " ";
		cout << endl;

		range_update_l(1,1,tree_size/2,3,4,-10);
		for(auto it : tree)
			cout << it << " ";
		cout << endl;
		cout << range_sum(1,1,tree_size/2,2,4);



	}

}