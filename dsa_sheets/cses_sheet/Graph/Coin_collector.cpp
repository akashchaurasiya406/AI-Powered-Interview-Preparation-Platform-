// #include<bits/stdc++.h>
// using namespace std;
// unordered_map<int,list<int>>adjList;
// vector<int>visited,dfsvisited,vec,parent;
// vector<long long>dist;
// long long dfs(int start,int p){
//     long long maxval=0;
//     int val=0;
//     if(!visited[start]){
//         maxval=vec[start];
//         val=vec[start];
//     }
//     visited[start]=1;
//     dfsvisited[start]=1;
//     parent[start]=p;
//     for(auto ele:adjList[start]){
//         if(!visited[ele]){
//             maxval=max(maxval,val+dfs(ele,start));
//         }
//         else{
//             if(!dfsvisited[ele]){
//                 maxval=max(maxval,val+dist[ele]);
//             }
//             else{
//                 if(start!=parent[ele]){
//                     maxval=max(maxval,val+dfs(ele,start));
//                 }
//             }
//         }
//     }
//     dfsvisited[start]=0;
//     return dist[start]=maxval;
// }

// int main(){
//     int n,m;
//     cin>>n>>m;
//     vec.resize(n+1);
//     for(int i=0;i<n;i++){
//         int k;
//         cin>>k;
//         vec[i+1]=k;
//     }
//     for(int i=0;i<m;i++){
//         int u,v;
//         cin>>u>>v;
//         adjList[u].push_back(v);
//     }
//     long long maxval=LLONG_MIN;
//     visited.resize(n+1,0);
//     dfsvisited.resize(n+1,0);
//     dist.resize(n+1,0);
//     parent.resize(n+1,0);
//     for(int i=1;i<=n;i++){
//         if(!visited[i]){
//             maxval=max(maxval,dfs(i,0));
//         }
//     }
//     for(int i=1;i<=n;i++){
//         cout<<dist[i]<<" ";
//     }
//     cout<<endl;
//     cout<<maxval<<endl;
//     return 0;
// }




 