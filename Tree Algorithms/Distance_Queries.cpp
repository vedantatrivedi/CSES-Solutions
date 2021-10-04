#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repp(i,a,b) for(ll i=a;i<=b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define deb(x) cerr << #x << "=" << x << endl
#define debb(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define mod ((ll)1e9+7)
#define N ((ll)3e6+20)
#define pb push_back
#define in insert
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define PI 3.1415926535897932384626
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define test ll t; cin>>t; while(t--)
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
ll dr[] = { -1, 1, 0, 0};
ll dc[] = {0, 0, 1, -1};
 
/*Functions*/
ll gcd(ll a, ll b);
ll exp(ll x, ll y, ll p);
ll exp(ll x, ll y);
void InverseofNumber();
void InverseofFactorial();
void factorial();
ll Binomial(ll n, ll R);
 
 
ll factorialNumInverse[N + 1];
ll naturalNumInverse[N + 1];
ll fact[N + 1];
 
void fileIO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
const ll maxN = 2e5 + 20;
const ll maxNN = 20;
vector<ll> v[maxN];
ll level[maxN] , LCA[maxN][maxNN + 1];
ll n, q;
 
void dfs(ll node , ll lvl , ll par) {
	level[node] = lvl;
	LCA[node][0] = par;
 
	for (ll child : v[node])
		if (child != par) {
			dfs(child , lvl + 1 , node);
		}
}
 
 
void init() {
	dfs(1 , 0 , -1);
 
	for (ll i = 1; i <= maxNN; i++) {
		for (ll j = 1; j < maxN; j++)
			if (LCA[j][i - 1] != -1) {
				ll par = LCA[j][i - 1];
				LCA[j][i] = LCA[par][i - 1];
			}
	}
}
 
ll getLCA(ll a , ll b) {
	if (level[b] < level[a]) swap(a , b);
 
	ll d = level[b] - level[a];
 
	while (d > 0) {
		ll i = log2(d);
		b = LCA[b][i];
 
		d -= 1 << i;
	}
 
	if (a == b) return a;
 
	for (ll i = maxNN; i >= 0; i--)
		if (LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
		{
			a = LCA[a][i] , b = LCA[b][i];
		}
 
	return LCA[a][0];
}
 
int main() {
	clock_t start, end;
	start = clock();
	speed
	// InverseofNumber(), InverseofFactorial(), factorial();
	// fileIO();
	cin >> n;
	cin >> q;
	for (ll i = 0; i < n - 1; i++) {
		ll x, y; cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	init();
	while (q--) {
		ll a, b; cin >> a >> b;
		ll lca = getLCA(a, b);
		cout << level[a] + level[b] - 2 * level[lca] << endl;
	}
 
 
 
 
	end = clock();
	double timeTaken = (double(end - start) * (double(1000))) / double(CLOCKS_PER_SEC);
	deb(timeTaken);
	return 0;
}
 
 
/*All Functions*/
ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
 
ll exp(ll x, ll y, ll p) {
	ll res = 1;
	while (y) {
		if (y % 2)
			res = (res * x % p) % p;
		x = (x * x) % p;
		y /= 2;
	}
	return res;
}
ll exp(ll x, ll y) {
	ll res = 1;
	while (y) {
		if (y % 2)
			res = (res * x ) ;
		x = (x * x) ;
		y /= 2;
	}
	return res;
}
void InverseofNumber() {
	naturalNumInverse[0] = naturalNumInverse[1] = 1;
	for (ll i = 2; i <= N; i++)
		naturalNumInverse[i] = naturalNumInverse[mod % i] * (mod - mod / i) % mod;
}
void InverseofFactorial() {
	factorialNumInverse[0] = factorialNumInverse[1] = 1;
	for (ll i = 2; i <= N; i++)
		factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % mod;
}
void factorial() {
	fact[0] = 1;
	for (ll i = 1; i <= N; i++)
		fact[i] = (fact[i - 1] % mod * i % mod) % mod;
}
ll Binomial(ll n, ll R) {
	ll ans = ((fact[n] * factorialNumInverse[R]) % mod * (factorialNumInverse[n - R]) % mod) % mod;
	return ans;
}
