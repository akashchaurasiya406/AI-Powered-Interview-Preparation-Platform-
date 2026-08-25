// Diameter of Tree
// cses sheet


// concept:-
           // The farthest distance of node any node is one of the end point of the diameter of 
           // the node 


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>adj[n+1];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>path(n+1);
    function<void(int,int)>dfs=[&](int node,int par){
        for(auto it:adj[node]){
            if(it==par)continue;
            path[it]=path[node]+1;
            dfs(it,node);
        }
    };
    dfs(1,0);
    int lastnode=1;
    for(int i=1;i<=n;i++){
        if(path[i]>path[lastnode])lastnode=i;
    }
    path.assign(n+1,0);
    dfs(lastnode,0);         // here adj[lastnode][0] will be the parent of the lastnode
                                            // as lastnode will be the leaf node 
    cout<<*max_element(path.begin(),path.end())<<'\n';
    return 0;
}