#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 1e3 , mxX = 1e5 , M = 1e9 + 7;
int n,x,h[mxN],s[mxN],dp[mxX+1]; // dp -> max no. of pages for a given price

int main(){
	cin >> n >> x;
	for (int i = 0; i < n; ++i)
	{
		cin >> h[i]; // price
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i]; // pages
	}
	for (int i = 0; i < n; ++i)
	{
		for( int j=x ; j>=h[i]; --j ){
			dp[j] = max( dp[j] , dp[ j - h[i] ] + s[i] );
		}
	}
	cout << dp[x];
	return 0;
}