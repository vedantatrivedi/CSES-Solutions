// Author: Vishvesh Trivedi (NerdyVisky)
// Solution to: Coin Piles problems under Introductory problems of the CSES Problem Set.

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t > 0)
    {
        ll a, b;
        cin >> a >> b;
        if (a > b)
        {
        swap(a, b);
        }
        if (b > (2 * a))
        {
            cout << ("NO") << endl;
        }
        else
        {

            if ((a - (b - a)) % 3 == 0)
            {
                cout << ("YES") << endl;
            }
            else
            {
                cout << ("NO") << endl;
            }
        }
        t--;
    }
    return 0;
}