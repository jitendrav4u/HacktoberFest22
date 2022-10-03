#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int>adj[], vector<int>&d){
    for(auto &it: adj[node]){
        if(it!=parent){
            d[it] = d[node]+1;
            dfs(it,node,adj,d);
        } 
        
    }
    
}
int main(){
    int n;
    cin>>n;
    vector<int>adj[n+1];
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector<int>d(n+1,0);
    dfs(1,-1,adj,d);
    int end = 0;
    for(int i=1;i<=n;i++) end=max(end,d[i]),d[i]=0;
    // cout<<end<<"\n";
    dfs(end,-1,adj,d);
    int diameter=0;
    for(int i=1;i<=n;i++) diameter=max(diameter,d[i]);
    cout<<diameter<<"\n";
}