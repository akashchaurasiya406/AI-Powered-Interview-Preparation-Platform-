// method 1
// BM
// bfs used for all node 
// tle because we used matrix intead of list 



// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<int>>mat;
// vector<int>visited,dist;
// int main(){
//     int n;
//     cin>>n;
//     mat.resize(n,vector<int>(n));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cin>>mat[i][j];
//         }
//     }
    
//     function<void(int,int)>bfs=[&](int node,int n){
//         queue<pair<int,int>>q;
//         q.push({0,node});
//         visited[node]=1;
//         while(!q.empty()){
//             auto[d,u]=q.front();
//             q.pop();
//             for(int i=0;i<n;i++){
//                 if(!mat[u][i])continue;
//                 if(visited[i] && i==node){
//                     dist[node]=d+1;
//                     return ;
//                 }
//                 else if(!visited[i]){
//                     visited[i]=1;
//                     q.push({d+1,i});
//                 }
//             }
//         }
//     };

//     dist.resize(n,-1);
//     for(int i=0;i<n;i++){
//         visited.resize(n,0);
//         bfs(i,n);
//         visited.clear();
//     }
//     for(int i=0;i<n;i++){
//         if(dist[i]==-1){
//             cout<<"NO WAY\n";
//         }
//         else{
//             cout<<dist[i]<<"\n";
//         }
//     }
//     return 0;
// }





// method 2
// same as method 1
// give tle
// TC=O(v*(v+e)) if graph is dense the e=V^2
// which cause TC=O(V^3)



// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<int>>mat;
// vector<int>visited,dist;
// unordered_map<int,list<int>>adj;

// void bfs(int node,int& n){
//     queue<pair<int,int>>q;
//     q.push({0,node});
//     visited[node]=1;
//     while(!q.empty()){
//         auto[d,u]=q.front();
//         q.pop();
//         for(auto it:adj[u]){
//             if(visited[it] && it==node){
//                 dist[node]=d+1;
//                 return ;
//             }
//             else if(!visited[it]){
//                 visited[it]=1;
//                 q.push({d+1,it});
//             }
//         }
//     }
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n;
//     cin>>n;
//     mat.resize(n,vector<int>(n));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cin>>mat[i][j];
//             if(mat[i][j]){
//                 adj[i].push_back(j);
//             }
//         }
//     }

//     dist.resize(n,-1);
//     for(int i=0;i<n;i++){
//         visited.resize(n,0);
//         bfs(i,n);
//         visited.clear();
//     }
//     for(int i=0;i<n;i++){
//         if(dist[i]==-1){
//             cout<<"NO WAY\n";
//         }
//         else{
//             cout<<dist[i]<<"\n";
//         }
//     }
//     return 0;
// }







// method 3
// same as method 2
// but difference is that here we are list and not using visited vector
// because work cab be done using only distance vector 
// Tc=O(n*(n+e))


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n);

    // Read adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x)
                adj[i].push_back(j);
        }
    }

    for (int src = 0; src < n; src++) {

        vector<int> dist(n, -1);
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        int ans = -1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {

                if (v == src) {
                    ans = dist[u] + 1;
                    while (!q.empty()) q.pop();
                    break;
                }

                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        if (ans == -1)
            cout << "NO WAY\n";
        else
            cout << ans << '\n';
    }

    return 0;
}



