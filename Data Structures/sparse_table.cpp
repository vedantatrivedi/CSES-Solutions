#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define test    int t; cin>>t; while(t--)
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int32_t main(){
	
	fast_io;

	int n;
	cin >> n;
	int x = log2(n)+1;

	/* Sparse table 

		st[i][j] gives min of [arr[i],arr[i+(2^j)-1]
		min([arr[i],arr[i+(2^j)-1]]) = min (  min([arr[i],arr[i+2^(j-1)-1]) ,  min(arr[i+2^(j-1),i+(2^j)-1])  )
		Using above st[i][j] = min(st[i][j-1],st[i+ 2^(j-1))][j-1])

	*/

	int st[n][x]={};
	for(int i=0;i<n;i++)
		cin >> st[i][0];

	// For finding min
	// for(int j=1;j<x;j++){
	// 	for(int i=0;i+(1<<(j-1))<n;i++){
	// 		st[i][j] = min(st[i][j-1],st[i+ (1<<(j-1))][j-1]);
	// 	}
	// }


	// USE PREFIX ARRAY INSTEAD FOR SUM, faster and less space
	// For finding sum
	for(int j=1;j<x;j++){
		for(int i=0;(i+(1<<(j-1)))<n;i++){
			st[i][j] = st[i][j-1] + st[i+ (1<<(j-1))][j-1];
		}
	}



	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<x;j++){
	// 		cout << st[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	int q;
	cin >> q;
	for(int i=0;i<q;i++){

		int l,r;
		cin >> l >> r;

		// Here the range [l,l+2^p-1] and [r-2^p+1,r] might overlap but covers the whole range [l,r]
		// int p = log2(r-l+1);
		// cout << min(st[l][p],st[r-(1<<p)+1][p]) << endl;

		int p = r-l+1;
		int sum = 0;
		for(int i=0;i<32;i++){
			if(p & (1<<i)){
				sum += st[l][i];
				l += (1<<i);
			}
		}
		cout << sum << endl;

	}

}
