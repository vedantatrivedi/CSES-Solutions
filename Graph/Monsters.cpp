/*
link : https://codeforces.com/blog/entry/78420
Logic:

Step 1: Apply BFS for all monsters. Store in dist array, d2[i][j], shortest time among all monsters to reach, coordinate (i, j).

Step 2: Apply BFS for A. Store in d1 array, shortest time from A to coordinate (i, j). It is only possible to reach that coordinate if d1[i][j] < d2[i][j]. Check if we have reached the border.

Step 3: Backtrack to generate the path. 
*/


#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int n,m, si,sj;
const int mxN = 1e3;
string s[mxN]; // string matrix
bool vis[mxN][mxN];

int di[4] = {1,0,-1,0}, dj[4] = {0,1,0,-1}, d1[mxN][mxN], d2[mxN][mxN], p1[mxN][mxN], p2[mxN][mxN];

const char dc[4] = { 'D','R','U','L' };

bool e(int i,int j){
	return i>=0 && i<n && j<m && s[i][j]=='.' && !vis[i][j];
}

void bfs(vector<ar<int,2>> v1, int d[mxN][mxN], int p[mxN][mxN]){
	queue<ar<int,2>> qu;   // ar<int,2> defines an array of length 2
	memset(vis,0,sizeof(vis));
	memset(d,0x3f,sizeof(d1)); // 0x3f is analogus to INT_MAX , but also avoids overflow
	for( ar<int,2> a : v1 ){
		qu.push(a);  // push all monsters into queue at begining
		vis[a[0]][a[1]] = 1;
		d[a[0]][a[1]] = 1; // set d to zero
	}
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
			vis[ni][nj] = 1;  // why ? -> because whichever monster reaches first should put its time
			d[ni][nj] = d[u[0]][u[1]] + 1; // prev dist plus one 
			p[ni][nj] = k;
		}
	}
}
 
int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	
	cin >> n >> m;
	vector<ar<int,2>> v2; // vector of all monsters
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
		for (int j = 0; j < m; ++j)
		{
			if( s[i][j]=='A' ){
				si =i , sj =j; s[i][j]=='.';
			}
			if( s[i][j]=='M' ){
				v2.push_back({i,j});s[i][j] = '.';
			}
		}
	}

	bfs({{si,sj}},d1,p1);
	bfs(v2,d2,p2);

	int ti = -1,tj;

	for (int i = 0; i < n; ++i)
	{
		// (i,0) , (i,m-1) testing boundry for '.'
		if( d1[i][0] < d2[i][0] )
			ti = i,tj=0;
		if( d1[i][m-1]< d2[i][m-1])
			ti = i,tj =m-1;
	}
	for(int j=0; j<m ;++j){
		// (0,j) , (n-1,j)
		if( d1[0][j] < d2[0][j] )
			ti=0,tj=j;
		if( d1[n-1][j] < d2[n-1][j] )
			ti=n-1,tj=j;
	}

	if(~ti){
		cout << "YES\n";
		string t;
		while( ti^si || tj^sj ){
			t += dc[p1[ti][tj]];
			int dd = p1[ti][tj]^2;
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
