#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj;
vector<int>parent,visited,depth;

bool dfs(int node,int par,int k){
    visited[node]=1;
    for(auto it:adj[node]){
        if(it==par)continue;
        if(visited[it]){
            if((depth[node]-depth[it]+1)>=k+1){
                cout<<(depth[node]-depth[it]+1)<<endl;
                int temp=node;
                while(temp!=it){
                    cout<<temp<<" ";
                    temp=parent[temp];
                }
                cout<<temp<<endl;
                return true;
            }
        }
        else{
            depth[it]=depth[node]+1;
            parent[it]=node;
            if(dfs(it,node,k))return true;
        }
    }
    return false;
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    adj.resize(n+1);
    parent.resize(n+1);
    visited.assign(n+1,0);
    depth.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            depth[i]=1;
            if(dfs(i,0,k))break;
        }
    }
    return 0;
}