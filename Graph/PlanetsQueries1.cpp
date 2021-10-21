#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mxN = 2e5;
int n,q,t[30][mxN];

int main(){
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
	{
		cin >> t[0][i]; --t[0][i];
	}
	for (int j = 1; j < 30; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			t[j][i] = t[j-1][t[j-1][i]]; // t[x][y] means -> planet reached after teleporting pow(2,x) times from yth planet 
		}
	}

	/*
	ANALYZE that "matrix t" is a modified toeplitz matrix

	where rows are shifted to left by pow(2,i) on ith row !!
 
	*/

	// cout << "\n";

	// for (int i = 0; i < 30; ++i)
	// {
	// 	for (int j = 0; j < n; ++j)
	// 	{
	// 		cout << t[i][j]+1 << " ";
	// 	}
	// 	cout << "\n";
	// }

	while(q--){
		// cout << "\nQ :" << q << "\n";
		int x,k;
		cin >> x >> k; --x;
		for (int i = 0; i <30; ++i) // i here is the power of two i.e pow(2,i) , [remember 2^30 = 1e9 + (something) approximately] and k < 1e9 
		{
			if( k>>i & 1 ){ // k can be represented as sum of power of twos
				x = t[i][x];   // we are performing binary lifting here 
				// cout << x+1 << "\n";
			}
		}
		cout << x+1 << "\n"; 

	}
}

/*
i/p -
10 10
2 3 4 5 6 7 8 9 10 1
2 10
6 5
6 6
3 7
3 1
9 6
9 8
7 9
1 10
6 6

op-
2
1
2
10
4
5
7
6
1
2

*/