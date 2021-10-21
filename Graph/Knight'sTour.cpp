#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int n;

int di[8] = {1,2,2,1,-1,-2,-2,-1} , dj[8] = {2,1,-1,-2,-2,-1,1,2} ;
int vis[8][8];

bool free(int nx, int ny){
	return ( nx>=0 && nx<8 && ny>=0 && ny<8 && !vis[nx][ny] );
}

int deg( ar<int,2>  a ){
	int d =0;
	for (int i = 0; i < 8; ++i)
	{
		d+=free( a[0]+di[i], a[1]+dj[i] );
	}
	return d;
}

void dfs(int x,int y, int a){
	/*for (int i = 0; i < 8; ++i)
	{
		for(int j=0; j<8; ++j){
			cout << vis[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;*/
	vis[x][y]=a+1;
	if( a==63 ){
		for (int i = 0; i < 8; ++i)
		{
			for(int j=0; j<8; ++j){
				cout << vis[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	

	vector<ar<int,2>>p;
	for (int i = 0; i < 8; ++i)
	{
		int nx = x+di[i], ny = y+dj[i];
		if( free(nx,ny) ){
			p.push_back({nx,ny});
		}
	}
	sort(p.begin(),p.end(), []( const ar<int,2> &a, const ar<int,2> &b ){
		return deg(a)<deg(b);
	});
	for( ar<int,2> b : p ){
		dfs(b[0],b[1],a+1);
	}
	vis[x][y] = 0;
}

int main(){
	int x,y;
	cin >> x >> y , --x,--y;
	swap(x,y);
	dfs(x,y,0);
}
