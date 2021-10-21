


#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int mxN = 5e2, M =1e9+7;
int n;
ll dp[mxN*(mxN+1)/2+1];

int main(){
	cin >> n;
	int s = n*(n+1)/2;
	if(s&1){ // if s is not even
		cout << 0;
		return 0;
	}
	s/=2;
	dp[0] = 1; // dp[i] -> means number of ways to have sum = i using n indices BASE CASE
	// cout << "i " << "j " << "dp[j] " << "\n"; 
	for (int i = 1; i <= n; ++i)
	{
		// cout << " ans for n = " << i << "\n";
		for (int j = i*(i+1)/2; j>=i; --j )
		{ 
			dp[j] = (dp[j]+dp[j-i])%M; // dp[sum] + dp[sum-i]
			// cout << i << " " << j << " " << dp[j] << "\n"; 
		}
		// for (int i = 0; i < n*(n+1)/2+1 ; ++i)
		// {
		// 	cout << dp[i] << " ";
		// }
		// cout << "\n" << dp[i*(i+1)/4]*((M+1)/2)%M << "\n";
		// cout << "\n\n";
	}
	// for (int i = 0; i < n*(n+1)/2+2 ; ++i)
	// {
	// 	cout << dp[i] << " ";
	// }
	// cout << "\n\n";
	cout << dp[s]*((M+1)/2)%M;  // ((M+1)/2)%M -> means divide by 2
	return 0;
}
