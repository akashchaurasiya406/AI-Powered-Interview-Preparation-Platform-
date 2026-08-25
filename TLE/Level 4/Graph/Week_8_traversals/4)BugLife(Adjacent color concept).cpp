#include<bits/stdc++.h>
using namespace std;


vector<int>color;

bool dfs(int node,int val,int n,vector<int>&visited,vector<vector<int>>&adj){
    visited[node]=1;
    color[node]=val;
    bool ans=true;
    for(auto it:adj[node]){
        if(!visited[it]){
            if(!dfs(it,!val,n,visited,adj)){
                ans=false;
            }
        }
        else{
            if(color[it]==val){
                ans=false;
            }
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    int no=1;
    while(no<=t){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>adj(n+1);
        vector<int>visited(n+1,0);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        color.resize(n+1);
        bool ans=true;
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                if(!dfs(i,0,n,visited,adj)){
                    ans=false;
                    break;
                }
            }
        }
        cout << "Scenario #" << no << ":\n";
        if (!ans) {
            cout << "Suspicious bugs found!\n\n";
        }
        else {
            cout << "No suspicious bugs found!\n\n";
        }
        no++;
    }
    return 0;
}