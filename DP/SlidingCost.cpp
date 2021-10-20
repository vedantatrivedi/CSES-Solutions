#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int mxN = 2e5;
int n,k;
ll a[mxN],sb,st; // st -> sum of top , sb -> sum of bottom
ar<int,2> med = {-1};
set<ar<int,2>> bot,top;

void fix(){
	int m = bot.size() + top.size() + 1;
	if( bot.size()< (m-1)/2 ){
		bot.insert(med);
		sb+=med[0];
		med=*top.begin();
		top.erase(med);
		st-=med[0];
	}
	if( bot.size()> (m-1)/2 ){
		top.insert(med);
		st+=med[0];
		med=*--bot.end();
		bot.erase(med);
		sb-=med[0];
	}
}

void add (ar<int,2> x){
	if(med[0]==-1){
		med=x;return;
	}
	if( x<med ){
		bot.insert(x); sb+=x[0];
	}
	else{
		top.insert(x); st+=x[0];
	}
	fix();
}

void rem(ar<int,2> x){
	if( x==med ){ // change the median and prev median gets automatically deleted since it is not stored in any set
		// cout << "\n x " << x[0] << "\n";
		med=*top.begin();
		// cout << "\n med " << med[0] << "\n";
		top.erase(med);
		st-=med[0];
	}
	else if(x<med){
		bot.erase(x); sb-=x[0];
	}else{
		top.erase(x); st-=x[0];
	}
	fix();
}

int main(){
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	if( k==1 ){
		for (int i = 0; i < n; ++i)
		{
			cout << 0 << " ";
		}
		return 0;
	}
	for (int i = 0; i < k-1; ++i)
	{
		add( {a[i],i} );
	}
	for (int i = k-1; i < n; ++i)
	{
		add( {a[i],i} );
		// for( auto it : bot ){
		// 	cout << it[0] << " ";
		// }
		// cout << "\n";
		cout << st-med[0]*(ll)top.size() + med[0]*(ll)bot.size()-sb  << " "/*" med \n"*/;
		// for( auto it : top ){
		// 	cout << it[0] << " ";
		// }
		// cout << "\n";
		rem( {a[i-k+1],i-k+1} );
		// for( auto it : bot ){
		// 	cout << it[0] << " ";
		// }
		// cout << "\n";
		// for( auto it : top ){
		// 	cout << it[0] << " ";
		// }
		// cout << "\n";
		// cout << "\n\n";
	}
	return 0;
}
