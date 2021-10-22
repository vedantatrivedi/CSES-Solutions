// Solution to Palindrome reorder question under the CSES Introductary Problem set
// Author: Vishvesh Trivedi (NerdyVisky)


#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main(){
    string str;
    cin>>str;
    sort(str.begin(), str.end());
    ll n = str.length();
    vector<char> strP(n);
    ll i = 0; 
    ll k = 0;
    ll flag = 1;
    char odd = 'a';
    while(i<n-1){
        if(str[i]==str[i+1]){
            strP[k] = str[i];
            strP[n-1-k] = str[i+1];
            k++;
            i += 2;
        }
        else{
            if(n%2 == 0){
                cout<<("NO SOLUTION")<<endl;
                return 0;
            }else{
                if(flag!=0){
                    odd = str[i];
                    i++;
                    flag = 0;
                }else{
                    cout<<("NO SOLUTION")<<endl;
                    return 0; 
                }
            }
        }
    }
    if((n%2 != 0) && (odd == 'a')){
        odd = str[n-1];
        flag = 0;
    }
    if(flag==0){
    strP[(n-1)/2] = odd;
    }
    for(int i = 0; i<n; i++){
        cout<<(strP[i]);
    }
    return 0;
}