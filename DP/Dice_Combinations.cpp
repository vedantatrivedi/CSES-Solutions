#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
int main()
{
	ll mod=(ll)(1e9+7);
	ll n;
	cin>>n;
	int dp[n+100]={'\0'};
	dp[0]=1;
	ll i=0;
	for(i=1;i<=n;i++)
	{
		for(int k=1;k<7&&(i-k>=0);k++)
		{
			dp[i]=(dp[i]%mod+dp[i-k]%mod)%mod;
		}
	}
	cout<<dp[n]<<"\n";
}
