#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int mxN = 2e5;
int n,q;
ll x[mxN+1];

int main(){
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i+1];
		x[i+1]+= x[i];
	}
	while(q--){
		int a,b;
		cin >> a >> b , --a;
		cout << x[b]-x[a] << "\n";
	}
	return 0;
}