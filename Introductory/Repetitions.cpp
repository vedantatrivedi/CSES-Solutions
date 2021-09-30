#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int mx = 0;
    int i = 0;
    while(i<s.length()){
        char curr = s[i];
        int curr_max = 0;
        while(i<s.length() && s[i]==curr){
            i++;
            curr_max++;
        }
        mx = max(curr_max,mx);
    }
    cout<<mx<<endl;
}