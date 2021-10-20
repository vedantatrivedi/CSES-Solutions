#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 500;
int dp [mxN+1][mxN+1];

int main(){
	int a,b;
	cin >> a >> b;
	for (int i = 1; i <=a ; ++i)
	{
		for (int j = 1; j <= b; ++j)
		{
			if( i^j ){ // i^j -> means if i!=j
				dp[i][j] = 1e9; // reinitialize
			}	
			for (int k = 1; k < i; ++k) // we try to do horizontal cut
			{
				dp[i][j] = min(dp[i][j],dp[k][j]+dp[i-k][j]+1 );
			}
			for (int k = 1; k < j; ++k) // we try to do vertical cut
			{
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j-k]+1 );
			}
		}
	}
	cout << dp[a][b];

	return 0;
}