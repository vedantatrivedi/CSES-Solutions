#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000];
int s[(int)(1e6+10)],x,n;
int32_t main()
{
	cin>>n>>x;
	s[0]=0;
	int i,j,k;
	for(i=0;i<n;i++) cin>>a[i];
	for(i=1;i<=x;i++)
	{
		s[i]=INT_MAX;
		for(j=0;j<n;j++)
			if(i-a[j]>=0)
				s[i]=min(s[i],s[i-a[j]]+1);
	}
	if(s[x]!=INT_MAX)
	cout<<s[x];
	else cout<<"-1";
}
