#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int mxN = 100, mxX = 1e6, M = 1e9+7;
int n,x,c[mxN];
ll dp[mxX+1]; // dp[i] -> min coins to achieve sum = i 
int main(){
	cin >> n >> x;
	for (int i = 0; i < n; ++i)
	{
		cin >> c[i];
	}
	dp[0] = 1;
	for( int j=0; j<n; ++j)// loop through possible coins
	{
		for (int i = 1; i <= x; ++i){
			if(c[j]<=i){
				dp[i] = (dp[i]+dp[i-c[j]])%M;
			}
		}
	}

	cout << dp[x] ;
	return 0;
}
