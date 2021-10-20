/*
link : https://www.youtube.com/watch?v=KD7FpmuZgQ8
link : https://www.youtube.com/watch?v=uSFzHCZ4E-8
BIT[i] = stores sum from l to r
l = i - pow(2,x) +1
r = i
x = position of first 1 in binary representation of r (0th indexing from right to left)

pattern -
if i is odd range is [i,i]
if i is a power of 2 range is [1,i]
*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 1e3;
int n,q,ft[mxN+1][mxN+1];
string s[mxN];

void upd(int i2, int j2, int x){ // upd only changes Binary indexed tree
	for(int i=i2+1; i<=n; i+=i&-i){ // The parent can be obtained by incrementing the last set bit of the current index, i.e., index = index + (index & (-index))
		for(int j=j2+1; j<=n; j+=j&-j){
			ft[i][j] +=x ;
		}
	}
}

int qry(int i2,int j2){  //The parent can be obtained by removing the last set bit from the current index, i.e., index = index – (index & (-index))
	int r = 0;
	for(int i=i2; i; i-=i&-i){
		for(int j=j2; j; j-=j&-j){
			r+=ft[i][j];
		}
	}
	return r;
}

int main(){
	cin >> n >> q;
	for(int i=0; i<n; ++i){
		cin >> s[i];
		for(int j=0; j<n; ++j){
			if(s[i][j]=='*'){
				upd(i,j,1);
			}
		}
	}
	for(int i=0; i<q; ++i){
		int qt;
		cin >> qt;
		if( qt==1 ){
			int y,x;
			cin >> y >> x , --y,--x;
			upd(y,x,s[y][x]=='*'?-1:1);
			if(s[y][x]=='*'){
				s[y][x]='.';
			}else{
				s[y][x]='*';
			}
		}else{
			int y1,x1,y2,x2;
			cin >> y1 >> x1 >> y2 >> x2;
			cout << qry(y2,x2) - qry(y1-1,x2) - qry(y2,x1-1) + qry(y1-1,x1-1) << "\n";
		}
	}
	return 0;
}
