// Author: Vishvesh Trivedi (NerdyVisky)
// Solution to the problem - Gray Code under the CSES Introductory Problem set.
#include <bits/stdc++.h>
using namespace std;

void grayCode(int n, string str = "")
{
    if (n == 0)
    {
        string gray = "";
        gray += str[0];
        for(int i = 1; i< str.length(); i++){
            if(str[i-1] == str[i]){
                gray += "0";
            }else{
                gray += "1";
            }
        }
        cout << (gray) << endl;
        return;
    }
    grayCode(n - 1, str + "0");
    grayCode(n - 1, str + "1");
}

int main()
{
    int n;
    cin >> n;
    grayCode(n);
    return 0;
}