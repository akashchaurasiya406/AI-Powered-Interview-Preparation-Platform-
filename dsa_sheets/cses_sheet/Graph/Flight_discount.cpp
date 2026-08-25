// youtube logic:-
                // see each inserted in priority queue as package which 
                // include (dist_req,package used or not,node)
                // dardeve channel

// code 1a:-
          // BM


#include<bits/stdc++.h>
using namespace std;

class Package{
public:
    int u;
    long long w;
    bool used;
    Package(int a,long long b,bool c){
        u=a;w=b;used=c;
    }
};

unordered_map<int,list<pair<int,int>>>adj;

void Dijkstra(int start,int n){
    vector<vector<long long>>dist(n+1,vector<long long>(2,LLONG_MAX));         // 0 for not used and 1 for used 
    dist[start][0]=0;
    Package p(start,0LL,0);

    auto cmp =[](const Package &p1,const Package &p2){
        return p1.w>p2.w;
    };
    priority_queue<Package,vector<Package>,decltype(cmp)>pq(cmp);

    pq.push(p);
    while(!pq.empty()){
        Package p1=pq.top();pq.pop();
        if(p1.w>dist[p1.u][p1.used]) continue;           // this remove tle part suggested by chatgpt imp
        for(auto ele:adj[p1.u]){
            if(p1.used){         // used already
                if(dist[ele.first][1]>p1.w+ele.second){
                    dist[ele.first][1]=p1.w+ele.second;
                    Package p2(ele.first,dist[ele.first][1],1);
                    pq.push(p2);
                }
            }
            else{         // not used already
                if(dist[ele.first][0]>p1.w+ele.second){
                    // not using 
                    dist[ele.first][0]=p1.w+ele.second;
                    Package p2(ele.first,p1.w+ele.second,0);
                    pq.push(p2);
                    // using
                    if(dist[ele.first][1]>p1.w+ele.second/2){
                        dist[ele.first][1]=p1.w+ele.second/2;
                        Package p3(ele.first,p1.w+ele.second/2,1);
                        pq.push(p3);
                    }
                } 
                else if(dist[ele.first][1]>p1.w+ele.second/2){
                    dist[ele.first][1]=p1.w+ele.second/2;
                    Package p2(ele.first,p1.w+ele.second/2,1);
                    pq.push(p2);
                }              
            }
        }
    }
    cout<<min(dist[n][0],dist[n][1])<<endl;
}

int main(){
    ios::sync_with_stdio(false);             // if uses then it get accepted otherwise it is not accepted
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    Dijkstra(1,n);
    return 0;
}




// code 2:-
         // used vector instead of unordered_map as it is slower compared to vector
         // chatgpt


// #include <bits/stdc++.h>
// using namespace std;

// struct Package {
//     int u;
//     long long w;
//     bool used;
//     Package(int a, long long b, bool c) : u(a), w(b), used(c) {}
// };

// // Custom comparator for min-heap
// struct cmp {
//     bool operator()(const Package &a, const Package &b) {
//         return a.w > b.w;
//     }
// };

// void Dijkstra(int start, int n, vector<vector<pair<int,int>>> &adj) {
//     vector<vector<long long>> dist(n + 1, vector<long long>(2, LLONG_MAX));
//     dist[start][0] = 0;

//     priority_queue<Package, vector<Package>, cmp> pq;
//     pq.push(Package(start, 0LL, 0));

//     while(!pq.empty()) {
//         Package p1 = pq.top(); pq.pop();

//         if(p1.w > dist[p1.u][p1.used]) continue; // skip outdated states

//         for(auto &ele : adj[p1.u]) {
//             int v = ele.first;
//             long long w = ele.second;

//             if(p1.used == 0) {
//                 // Case 1: not used discount yet
//                 if(dist[v][0] > p1.w + w) {
//                     dist[v][0] = p1.w + w;
//                     pq.push(Package(v, dist[v][0], 0));
//                 }
//                 // Case 2: use discount
//                 long long half = p1.w + w / 2;
//                 if(dist[v][1] > half) {
//                     dist[v][1] = half;
//                     pq.push(Package(v, half, 1));
//                 }
//             } else {
//                 // Already used discount
//                 if(dist[v][1] > p1.w + w) {
//                     dist[v][1] = p1.w + w;
//                     pq.push(Package(v, dist[v][1], 1));
//                 }
//             }
//         }
//     }

//     cout << min(dist[n][0], dist[n][1]) << endl;
// }

// int main() {
//     ios::sync_with_stdio(false);             // if uses then it get accepted otherwise it is not accepted
//     cin.tie(nullptr);

//     int n, m;
//     cin >> n >> m;
//     vector<vector<pair<int,int>>> adj(n + 1);          // faster then unordered_map

//     for(int i = 0; i < m; i++) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         adj[u].push_back({v, w});
//     }

//     Dijkstra(1, n, adj);
//     return 0;
// }



