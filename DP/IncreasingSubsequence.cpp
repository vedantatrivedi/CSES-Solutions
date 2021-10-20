#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int mxN = 2e5;
int n;

int main(){
	cin >> n;
	vector <int> v;
	for(int i=0 ;i <n; ++i){
		int a;
		cin >> a;

		int p = lower_bound(v.begin(),v.end(), a ) - v.begin() ;
		// cout << a << " " << p << " " << v.size() << "\n";
		if( p == v.size()){
			v.push_back(a);
		}else{
			v[p] = a;
		}
		// for( int x : v){
		// 	cout << x << " ";
		// }

		// cout << "\n\n";
	}
	cout << v.size();

	return 0;
}