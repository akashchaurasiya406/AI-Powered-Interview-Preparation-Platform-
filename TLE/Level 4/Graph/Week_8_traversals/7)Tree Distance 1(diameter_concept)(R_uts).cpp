// see tree of cses sheet


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj;
vector<int>dist1,dist2;


pair<int,int> diameter(int u,int par){
    int ans=0;
    int node=u;
    for(auto v:adj[u]){
        if(v==par)continue;
        auto[d,x]=diameter(v,u);
        if(ans<(1+d)){
            ans=1+d;
            node=x;
        }
    }
    return {ans,node};
}


void dfs(int u,int par,int d,vector<int>&dist){
    int ans=0;
    dist[u]=d;
    for(auto v:adj[u]){
        if(v==par)continue;
        dfs(v,u,d+1,dist);
    }
}


int main(){
    int n;
    cin>>n;
    adj.resize(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    pair<int,int>p1=diameter(1,0);
    pair<int,int>p2=diameter(p1.second,0);
    dist1.assign(n+1,0);
    dist2.assign(n+1,0);
    dfs(p1.second,0,0,dist1);
    dfs(p2.second,0,0,dist2);
    for(int i=1;i<=n;i++){
        cout<<max(dist1[i],dist2[i])<<" ";
    }
    return 0;
}



