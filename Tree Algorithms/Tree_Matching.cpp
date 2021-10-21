#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vector<vector<int> > graph(n+1);
    
    for(int i=0;i<n-1;++i){
        int a,b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    vector<int> color(n+1);
    vector<int> visited(n+1,0);

    q.push(1);
    color[1] = 0;
    visited[1] = 1;
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(int i:graph[node]){
            if(!visited[i]){
                visited[i] = 1;
                color[i] = (color[node]+1)%2;
                q.push(i);
            }
        }
    }
    vector<int> first;
    vector<int> second;
    for(int i=1;i<=n;++i){
        if(color[i]==0) first.push_back(i);
        else second.push_back(i);
    }
    int count = 0;
    fill(all(visited),0);
    if(first.size() < second.size()) swap(first,second);
    for(int i=0;i<first.size();++i) {
        visited[first[i]] = 1;
        for(int it:graph[first[i]]){
            if(!visited[it]){
                visited[it] = 1;
                count++;
                break;
            }
        }
    }
    cout << count << '\n';
    return 0;
}