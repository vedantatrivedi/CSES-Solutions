#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector <int> order,eq;

void initialisation(){
	int arr[100]={};
	for(int i=0;i<n;i++)
		arr[s[i]-'$']++;
	for(int i=1;i<100;i++)
		arr[i]+=arr[i-1];
	for(int i=n-1;i>=0;i--){
		arr[s[i]-'$']--;
		order[arr[s[i]-'$']] = i;
	}

	eq[order[0]]=0;
	for(int i=1;i<n;i++){
		if(s[order[i]]==s[order[i-1]])
			eq[order[i]]=eq[order[i-1]];
		else{
			eq[order[i]]=eq[order[i-1]]+1;
		}
	}
}

vector <int> SortDouble(int L,vector <int> order,vector <int> eq){
	vector <int> newOr(n,0);
	int count[n]={};
	for(int i=0;i<n;i++)
		count[eq[i]]++;
	for(int i=1;i<n;i++)
		count[i] += count[i-1];
	for(int i=n-1;i>=0;i--){
		int s = eq[(order[i]-L+n)%n];
		count[s]--;
		newOr[count[s]] = (order[i]-L+n)%n;
	}
	return newOr;
}

vector <int> updateEq(int L,vector <int> order,vector <int> eq){

	vector <int> newEq(n,0);

	for(int i=1;i<n;i++){
		int cur = order[i];
		int prev = order[i-1];
		int mid = (cur + L)%n;
		int mid_prev = (prev+L)%n;

		if(eq[cur]==eq[prev] && eq[mid]==eq[mid_prev])
			newEq[cur] = newEq[prev];
		else
			newEq[cur] = newEq[prev]+1;
	}
	return newEq;
}

vector <int> SuffixArr(){
	initialisation();
	int L = 1;
	for(auto it : order)
		cout << it << " ";
	cout << endl;

	for(auto it : eq)
		cout << it << " ";
	cout << endl;
	while(L<n){
	order = SortDouble(L,order,eq);
	eq = updateEq(L,order,eq);
	cout << L << endl;
	for(auto it : order)
		cout << it << " ";
	cout << endl;

	for(auto it : eq)
		cout << it << " ";
	cout << endl;
	L = L*2;
	}

}


int main(){
	cin >> s;
	s = s + '$';
	n = s.size();
	order = eq = vector<int>(n);

	SuffixArr();
	for(auto it : order)
		cout << it << " ";
	cout << endl;

	for(auto it : eq)
		cout << it << " ";
	cout << endl;

}