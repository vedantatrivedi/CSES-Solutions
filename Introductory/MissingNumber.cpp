#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    unordered_map<int,int> mp;
    for(int i=0;i<n-1;i++)
    {
        int a;
        cin>>a;
        mp[a]++;
    }
    for(int i=1;i<=n;i++){
        if(mp.find(i)==mp.end()){
            cout<<i<<endl;
        }
    }
    
    return 0;
}