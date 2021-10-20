#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 1e3, M =1e9 + 7;
int n,dp[mxN][mxN];
string s[mxN];

int main(){
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
	}
	dp[0][0] = 1; // BASE CASE
	for (int i = 0; i < n; ++i)
	{
		for(int j=0; j<n; ++j){
			if(i){
				dp[i][j] += dp[i-1][j];
			}
			if(j){
				dp[i][j] += dp[i][j-1];
			}
			dp[i][j]%=M;
			if( s[i][j]=='*' ){
				dp[i][j] = 0;
			}
		}
	}
	cout << dp[n-1][n-1];
	return 0;
}


















































// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define ar array

// const int mxN = 1e3, M =1e9 + 7;
// int n,dp[mxN][mxN];
// string s[mxN];

// int main(){
// 	cin >> n;
// 	for (int i = 0; i < n; ++i)
// 	{
// 		cin >> s[i];
// 	}
// 	for (int i = 0; i < n; ++i)
// 	{
// 		dp[0][i] = 1;
// 		dp[i][0] = 1;
// 		if(s[0][i]=='*') dp[0][i] = 0;
// 		if(s[i][0]=='*') dp[i][0] = 0;
// 	}
// 	for (int i = 1; i < n; ++i)
// 	{
// 		for( int j=1; j<n; ++j){
// 			dp[i][j] = dp[i-1][j] + dp[i][j-1];
// 			if( s[i][j]=='*' ){
// 				dp[i][j] = 0;
// 			}
// 		}
		
// 	}
// 	cout << dp[n-1][n-1];
// 	return 0;
// }

