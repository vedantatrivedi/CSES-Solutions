#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int n,m, si,sj, ti,tj;
const int mxN = 1e3;
string s[mxN],p[mxN]; // string matrix

int di[4] = {1,0,-1,0}, dj[4] = {0,1,0,-1}, d[mxN][mxN];

const char dc[4] = { 'D','R','U','L' };

bool e(int i,int j){
	return i>=0 && i<n && j<m && s[i][j]=='.';
}
 
int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
		for (int j = 0; j < m; ++j)
		{
			if( s[i][j]=='A' ){
				si =i , sj =j;
			}
			if( s[i][j]=='B' ){
				ti =i , tj =j; s[i][j] = '.';
			}
		}
		p[i] = string(m,0); // to backtrack the ans
	}

	// BFS gives us shortest path in a graph
	queue<ar<int,2>> qu;   // ar<int,2> defines an array of length 2
	qu.push({si,sj});
	while( qu.size() ){
		ar<int,2>  u = qu.front();
		qu.pop();
		
		for (int k = 0; k < 4; ++k)
		{
			int ni = u[0] + di[k], nj = u[1] + dj[k];
			if( !e(ni,nj) ){
				continue;
			}
			qu.push({ni,nj});
			s[ni][nj] = '#'; // analogus to bool visited
			d[ni][nj] = k;
			p[ni][nj] = dc[k];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << d[i][j] << " ";
		}
		cout << "\n";
	}

	if(p[ti][tj]){
		cout << "YES\n";
		string t;
		while( ti^si || tj^sj ){
			t += p[ti][tj];
			int dd = d[ti][tj]^2;
			ti += di[dd];
			tj += dj[dd];
		}
		reverse(t.begin(),t.end());
		cout << t.size() << "\n";
		cout << t;
	}
	else
		cout << "NO";

	return 0;
}