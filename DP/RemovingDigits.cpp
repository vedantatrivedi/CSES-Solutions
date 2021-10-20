#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int mxN = 1e6;
int n,dp[mxN+1]; // dp[i] -> min moves to make i zero

int main(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		dp[i] = 1e9;
		int i2=i;
		while(i2){ // choose any one digit and check if it min
			dp[i] = min( dp[i], dp[i-i2%10] + 1 );
			i2/=10;
		}
	}
	cout << dp[n];

	return 0;
}