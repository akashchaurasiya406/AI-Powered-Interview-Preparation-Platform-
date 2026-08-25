// CODEFORCES:-
            // cf 580_c
            // kefa and park



// method 1
// BM

#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1],cats(n+1);
    for(int i=1;i<=n;i++){
        cin>>cats[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int curr=0;
    int ans=0;

    function<void(int,int,int)>dfs=[&](int node,int par,int curr){
        // cout<<node<<" "<<curr<<'\n';
        for(auto it:adj[node]){
            if(it==par)continue;
            if(curr+cats[it]>m)continue;
            if(cats[it]){
                dfs(it,node,curr+cats[it]);
            }
            else{
                dfs(it,node,0);
            }
        }
        if(curr<=m && adj[node].size()==1 && node!=1){            // check of leaf node 
            ans+=1;
        }
    };

    dfs(1,0,cats[1]);
    cout<<ans<<'\n';
    return 0;
}



// sir dfs 
// important


// function<int(int,int,int)>dfs=[&](int node,int par,int curr){
//     if(curr>m)return 0;
//     int isleaf=1,answer=0;
//     for(auto it;adj[node]){
//         if(it!=par){
//             isleaf=0;
//             if(cats[i]) answer+=dfs(it,node,curr+1);
//             else answer+=dfs(it,node,0);
//         }
//     }
//     if(isleaf) return 1;
//     return answer;
// };

// cout<<dfs(1,0,cats[1]);

