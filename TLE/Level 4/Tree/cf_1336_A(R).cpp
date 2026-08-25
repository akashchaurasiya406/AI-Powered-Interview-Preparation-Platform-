// CODEFORCES 1336 A
//  Linova and Kingdom



// method 1
// BM
// not completely solved
// logic:-
        // if k<=noofleaf_node then make those leaf node as industrial node whose level are higher
        // if k>noofleaf_node then make all leaf node as industrial node first then find the cnt of 
        // non of leaf node present below a non leaf node
        // then sort the non leaf node based on no of leaf  node present below it in increasing order
        // and appoint these nodes as industrial cities 


// #include<bits/stdc++.h>
// using namespace std;

// unordered_map<int,int>leaf;
// void dfs(int node,int par,vector<int>adj[],vector<pair<int,int>>&level,int l){
//     level[node]={l,node};
//     if(adj[node].size()==0)leaf[node]=1;
//     for(auto it:adj[node]){
//         if(it==par)continue;
//         dfs(it,node,adj,level,l+1);
//     }
// }


// int findcnt(int node,int par,vector<int>adj[],vector<int>&cnt){
//     if(leaf[node]){
//         return 1;
//     }
//     int ans=0;
//     for(auto it:adj[node]){
//         if(it==par)continue;
//         ans+=findcnt(it,node,adj,cnt);
//     }
//     cnt[node]=ans;
// }


// int main(){
//     int n,k;
//     cin>>n>>k;
//     vector<int>adj[n+1];
//     for(int i=0;i<n-1;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     vector<pair<int,int>>level(n+1);
//     dfs(1,0,adj,level,0);
//     sort(level.begin(),level.end(),greater());
//     vector<int>cnt(n+1,0);
//     findcnt(1,0,adj,cnt);
//     if(k<=leaf.size()){
//         for(int i=0;i<k;i++){
//             if(leaf[level[i].second]){
//                 leaf[level[i].second]=2;
//             }
//         }

//     }
//     else{

//     }
//     return 0;
// }





// method 2 
// Sir solution
// choose those node with have largest depth-subtree values 
// if we choose one node as industrial node then the hpapiness will increase by depth and decrease by
// no of industrail node present below it which is equal to no of node present below it 


#include<bits/stdc++.h>
using namespace std;


int main(){
        int n,k;
        cin>>n>>k;
        vector<int>adj[n+1],depth(n+1,-1),subtree(n+1),arr(n);            // vector<int> cause default 0 initilizatoine
        iota(arr.begin(),arr.end(),1);          // this will fill ele from 1 to n

        for(int i=1;i<n;i++){
                int u,v;
                cin>>u>>v;
                adj[u].push_back(v);
                adj[v].push_back(u);
        }

        function<void(int,int)>dfs=[&](int node, int par){           // (int,int) show the type of parameter we are taking
                depth[node]=depth[par]+1;
                for(auto &it:adj[node]){
                        if(it==par)continue;
                        dfs(it,node);
                        subtree[node]+=subtree[it]+1;
                }
        };

        dfs(1,1);

        sort(arr.begin(),arr.end(),[&](int a,int b)             // custom comparator
        {
                return depth[a]-subtree[a]>depth[b]-subtree[b];
        });

        int answer=0;
        for(int i=0;i<k;i++){
                answer+=depth[arr[i]]-subtree[arr[i]];
        }
        cout<<answer<<'\n';
        return 0;
}


