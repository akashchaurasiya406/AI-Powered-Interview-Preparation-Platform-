// method 1
// BM
// using bellman ford taking edge value as -1 
// not good solution 
// coded by gpt
// gives tle as we know that TC of Bellman ford if O(VE)


// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m;
//     cin >> n >> m;

//     vector<vector<int>> adj(n + 1);

//     for (int i = 0; i < m; i++) {
//         int u, v;
//         cin >> u >> v;

//         adj[u].push_back(v);
//     }

//     const int INF = 1e9;

//     vector<int> dist(n + 1, INF);
//     vector<int> parent(n + 1, -1);

//     dist[1] = 0;

//     // Bellman-Ford
//     // Every edge has weight = -1
//     for (int i = 1; i <= n - 1; i++) {

//         bool changed = false;

//         for (int u = 1; u <= n; u++) {

//             if (dist[u] == INF)
//                 continue;

//             for (int v : adj[u]) {

//                 // weight = -1
//                 if (dist[v] > dist[u] - 1) {

//                     dist[v] = dist[u] - 1;
//                     parent[v] = u;

//                     changed = true;
//                 }
//             }
//         }

//         if (!changed)
//             break;
//     }

//     // Destination unreachable
//     if (dist[n] == INF) {
//         cout << "IMPOSSIBLE\n";
//         return 0;
//     }

//     // Reconstruct path
//     vector<int> path;

//     int node = n;

//     while (node != -1) {
//         path.push_back(node);
//         node = parent[node];
//     }

//     reverse(path.begin(), path.end());

//     cout << path.size() << '\n';

//     for (int x : path) {
//         cout << x << ' ';
//     }

//     cout << '\n';

//     return 0;
// }


// method 2
// BM 
// use BFS+Dijkstra mix by changing it's condition

#include<bits/stdc++.h>
using namespace std;

// unordered_map<int,list<int>>adj;
vector<vector<int>>adj;

void BFS(int start,int n){
    vector<int>dist(n+1,0);
    vector<int>parent(n+1,-1);
    // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    priority_queue<pair<int,int>>pq;        // can use this as well
    pq.push({0,1});
    while(!pq.empty()){
        auto[d,u]=pq.top();pq.pop();
        for(auto ele:adj[u]){
            if(dist[ele]<d+1){
                dist[ele]=d+1;
                parent[ele]=u;
                pq.push({dist[ele],ele});
            }
        }
    }
    if(dist[n]==0){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        vector<int>vec;
        int end=n;
        while(end!=1){
            vec.push_back(end);
            end=parent[end];
        }
        vec.push_back(1);
        reverse(vec.begin(),vec.end());
        cout<<vec.size()<<endl;
        int m=vec.size();
        for(int i=0;i<m;i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    BFS(1,n);
    return 0;
}


