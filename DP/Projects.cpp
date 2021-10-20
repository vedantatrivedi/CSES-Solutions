#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int mxN = 2e5;
int n;
ar<int,3> a[mxN];

int main(){
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i][1] >> a[i][0] >> a[i][2];
	}
	sort(a,a+n); // sort via ending time
	set<ar<ll,2> > dp; // set in cpp keeps elements sorted acc to ending time
	dp.insert({0,0}); //  { ending time t , max money till time t }
	ll ldp = 0;
	for (int i = 0; i < n; ++i)
	{
		// cout << " ending time " << a[i][1] ;
		auto it = dp.lower_bound({a[i][1]}); // lower bound of starting time
		--it;
		// cout << " prev ending time " << (*it)[0] << " prev ldp " << (*it)[1] ;
		ldp = max(ldp, (*it)[1] + a[i][2] );
		// cout << " ldp " << ldp;
		dp.insert({ a[i][0], ldp });
		// cout << " dp set \n ";
		// for( auto  x : dp ){
		// 	cout << (x)[0] << "/" << (x)[1] << "  ";  
		// }
		// cout << "\n\n";
	}
	
	cout << ldp;

	return 0;
}