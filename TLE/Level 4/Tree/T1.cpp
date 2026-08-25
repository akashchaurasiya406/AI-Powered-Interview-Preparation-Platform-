// Generic Tree:-
               // an undirected connected acyclic graph
               // e=n-1;
               // it also know ans N-array tree(each node can have n child)
               // vector<int>adj[n+1]; 
               // height=level+1

// Traversal:-
            // DFS
            // BFS

#include<bits/stdc++.h>
using namespace std;

map<int,pair<int,int>>visit_time;              // to keep track of intime and out time of node
int t=0;
vector<int>level_dfs,level_bfs;

void Dfs(int node,vector<int>adj[],int par){
    // entering the node
    cout<<node<<" ";
    for(auto child:adj[node]){
        if(child==par)continue;
        Dfs(child,adj,node);
    }
    // leaving the node 
}

void Bfs(int root,vector<int>adj[]){
    queue<pair<int,int>>q;
    q.push({root,-1});                // considering node start from 1 otherwise make par =1
    // {node,par};
    
    while(!q.empty()){
        int node=q.front().first;
        int par=q.front().second;
        cout<<node<<" ";
        q.pop();
        for(auto child:adj[node]){
            if(child!=par){
                q.push({child,node});
            }
        }
    }
}

void find_in_out_time(int node,int par,vector<int>adj[]){
    visit_time[node].first=t;
    t++;
    for(auto child:adj[node]){
        if(child==par)continue;
        find_in_out_time(child,node,adj);
    }
    visit_time[node].second=t;
    t++;
}

void findlevel_dfs(int node,vector<int>adj[],int par,int l){
    level_dfs[node]=l;
    for(auto child:adj[node]){
        if(child==par)continue;
        findlevel_dfs(child,adj,node,l+1);
    }
}

void findlevel_bfs(int node,vector<int>adj[]){
    int l=0;
    queue<pair<int,int>>q;
    q.push({node,-1});
    while(!q.empty()){
        int k=q.size();
        for(int i=0;i<k;i++){
            int node=q.front().first;
            int par=q.front().second;
            level_bfs[node]=l;
            q.pop();
            for(auto child:adj[node]){
                if(child==par)continue;
                q.push({child,node});
            }
        }
        l++;
    }
}

void check_ancestor(int u,int v){
    if(visit_time[u].first<visit_time[v].first && visit_time[u].second>visit_time[v].second){
        cout<<"Yes"<<endl;
    }
    cout<<"No"<<endl;
}

void find_height(int n){
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,level_dfs[i]+1);
    }
    cout<<ans<<endl;
}



int main(){
    int n;
    cin>>n;
    // tree creation
    vector<int>adj[n];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Dfs(1,adj,-1);

    Bfs(1,adj);
    
    // find in_time and out_time of node
    find_in_out_time(1,-1,adj);
     
    // to check whether u is ancestor of v or not
    // if(intime_u<intime_v && outtime_u>outtime_v) then u is ancestor or v
    // (in_u<in_v<out_v<<out_u)
    int u,v;
    cout<<"Enter the nodes whom which you want to check ancestory:\n";
    cin>>u>>v;
    check_ancestor(u,v);
    
    // find level of each node:-
                       // can find using dfs
                       // can also find using bfs
    // dfs approach
    level_dfs.resize(n+1,0);
    findlevel_dfs(1,adj,-1,0);

    // bfs approach
    level_bfs.resize(n+1,0);
    findlevel_bfs(1,adj);


    // find height of tree:-
                        // as height=level+1
                        // so use this concept
                        // can find using dfs also
    find_height(n);

    return 0;
}


// solve subordinate problem of cses sheet
// see solution in cses sheet folderr