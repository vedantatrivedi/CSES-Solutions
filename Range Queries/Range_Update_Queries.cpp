#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repp(i,a,b) for(ll i=a;i<=b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define endl "\n"

const ll MAX = 1e6;
const ll INF = 1e11;
ll a[MAX]; // the main input array
ll tree[2 * MAX]; // the segment tree array
ll lazy[2 * MAX]; //the lay tree
void buildTree(ll currentNode, ll startIndex, ll endIndex) {
	if (startIndex == endIndex) {
		tree[currentNode] = a[startIndex];
	}
	else {
		ll mid = (startIndex + endIndex) / 2;
		buildTree(2 * currentNode, startIndex, mid);
		buildTree((2 * currentNode) + 1, mid + 1, endIndex);
		tree[currentNode] = tree[2 * currentNode] ^ tree[(2 * currentNode) + 1];
	}
}
ll query(ll currentNode, ll startIndex, ll endIndex, ll queryStart , ll queryEnd) {
	if (lazy[currentNode] != 0) {
		ll dx = lazy[currentNode];
		lazy[currentNode] = 0;
		tree[currentNode] += dx * (endIndex - startIndex + 1);
		if (startIndex != endIndex) {
			lazy[2 * currentNode] += dx;
			lazy[2 * currentNode + 1] += dx;
		}
	}

	if (queryStart > endIndex || queryEnd < startIndex) //completely outside
		return 0;
	if (startIndex >= queryStart && endIndex <= queryEnd) { //completely inside
		return tree[currentNode];
	}
	ll mid = (startIndex + endIndex) / 2;
	return query(2 * currentNode, startIndex, mid, queryStart, queryEnd) + query(2 * currentNode + 1, mid + 1, endIndex, queryStart, queryEnd);
}
void update(ll currentNode, ll startIndex, ll endIndex, ll queryStart, ll queryEnd, ll value) {
	if (lazy[currentNode] != 0) {
		ll dx = lazy[currentNode];
		lazy[currentNode] = 0;
		tree[currentNode] += dx * (endIndex - startIndex + 1);
		if (startIndex != endIndex) {
			lazy[2 * currentNode] += dx;
			lazy[2 * currentNode + 1] += dx;
		}
	}
	if (startIndex > queryEnd || endIndex < queryStart) return;
	if (startIndex >= queryStart && endIndex <= queryEnd) {
		ll dx = (endIndex - startIndex + 1) * value;
		tree[currentNode] += dx;
		if (startIndex != endIndex) {
			lazy[2 * currentNode] += value;
			lazy[2 * currentNode + 1] += value;
		}
		return;
	}
	ll mid = (startIndex + endIndex) / 2;
	update(2 * currentNode, startIndex, mid, queryStart, queryEnd, value);
	update(2 * currentNode + 1, mid + 1, endIndex, queryStart, queryEnd, value);
	tree[currentNode] = tree[2 * currentNode] + tree[2 * currentNode + 1];
}

int main() {
	ll n;
	cin >> n;
	ll q; cin >> q;
	rep(i, 1, n + 1) cin >> a[i];
	buildTree(1, 1, n);

	while (q--) {
		ll code; cin >> code;
		if (code == 1) {
			ll l, r, value; cin >> l >> r >> value;
			update(1, 1, n, l, r, value);
		}
		else {
			ll x; cin >> x;
			cout << query(1, 1, n, x, x) << endl;
		}

	}

	return 0;
}
