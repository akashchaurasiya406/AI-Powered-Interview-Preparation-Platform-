// Method 1:-
           // using Bellman ford algo
           // if after n-1 relaxation dist[n] increases then +ve cycle is present in that case 
           // return -1 else if negative cycle is present in that case return that got value
           // while relaxation it condition is opp to that of used in finding the  SSSP



// code 1a:-
          // give tle as it have tc=O(n^3)
          // as well as wrong answer
                
// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<long long>>graph;
// vector<long long>dist;

// void Bellmanford(int n,int m){
//     dist.assign(n+1,LLONG_MIN);
//     dist[1]=0;
//     for(int k=0;k<n-1;k++){
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=n;j++){
//                 if(graph[i][j]!=0 && dist[i]!=LLONG_MIN && dist[j]<dist[i]+graph[i][j]){
//                     dist[j]=dist[i]+graph[i][j];
//                 }
//             }
//         }
//     }

//     for(int i=1;i<=n;i++){                   
//         for(int j=1;j<=n;j++){
//             if(graph[i][j]!=0 && dist[i]!=LLONG_MIN && dist[j]<dist[i]+graph[i][j]){
//                 if(graph[j][n]>0){              // this condition not check all tackel all conditions
//                     cout<<-1<<endl;
//                     return;
//                 }
//                 dist[j]=dist[i]+graph[i][j];
//             }            
//         }
//     }
//     cout<<dist[n]<<endl;
// }

// int main(){
//     long long n,m;
//     cin>>n>>m;
//     graph.assign(n+1,vector<long long>(n+1,0));
//     for(int i=0;i<m;i++){
//         long long a,b,x;
//         cin>>a>>b>>x;
//         graph[a][b]=x;
//     }
//     Bellmanford(n,m);
//     return 0;
// }



// code 2:-
         // tc=O(n*m)
         // wrong answer and tle as well 


// #include<bits/stdc++.h>
// using namespace std;

// unordered_map<int,list<pair<int,int>>>graph;
// vector<long long>dist;
// unordered_map<long long ,long long>mp;

// void Bellmanford(int n,int  m){
//     dist.assign(n+1,LLONG_MIN);
//     dist[1]=0;
//     for(int k=0;k<n-1;k++){
//         for(int i=1;i<=n;i++){
//             for(auto ele:graph[i]){
//                 if(dist[i]!=LLONG_MIN && dist[ele.second]<dist[i]+ele.first){
//                     dist[ele.second]=dist[i]+ele.first;
//                 }
//             }
//         }
//     }

//     long long val=dist[n];
//     for(int i=1;i<=n;i++){                   
//         for(auto ele:graph[i]){
//             if(dist[i]!=LLONG_MIN && dist[ele.second]<dist[i]+ele.first){
//                 if(mp[(long long)ele.second<<32 |n]>0){                          // still not tackles the all conditions
//                     cout<<-1<<endl;
//                     return ;
//                 }
//                 return ;
//                 dist[ele.second]=dist[i]+ele.first;
//             }
//         }
//     }
//     if(val!=dist[n]){
//         cout<<-1<<endl;
//     }
//     else{
//         cout<<dist[n]<<endl;
//     }
// }

// int main(){
//     int n,m;
//     cin>>n>>m;
//     for(int i=0;i<m;i++){
//         int a,b,x;
//         cin>>a>>b>>x;
//         graph[a].push_back({x,b});
//         mp[(long long)a<<32|b]=x;
//     }
//     Bellmanford(n,m);
//     return 0;
// }





// method 3
// chatgpt
          // wrong answer but not give tle

// #include <bits/stdc++.h>
// using namespace std;

// struct Edge {
//     int u, v;
//     long long w;
// };

// void BellmanFord(int n, vector<Edge> &edges) {
//     vector<long long> dist(n + 1, LLONG_MIN);
//     dist[1] = 0;

//     // Relax edges n-1 times
//     for (int i = 1; i <= n - 1; i++) {
//         for (auto &e : edges) {
//             if (dist[e.u] != LLONG_MIN && dist[e.v] < dist[e.u] + e.w) {
//                 dist[e.v] = dist[e.u] + e.w;
//             }
//         }
//     }

//     // Check for positive cycles reachable to the last node
//     for (auto &e : edges) {
//         if (dist[e.u] != LLONG_MIN && dist[e.v] < dist[e.u] + e.w) {             // as it don't tackle ass conditions 
//             // If e.v can reach node n (optional BFS/DFS check)
//             cout << -1 << endl;
//             return;
//         }
//     }

//     cout << dist[n] << endl;
// }

// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<Edge> edges(m);
//     for (int i = 0; i < m; i++) {
//         cin >> edges[i].u >> edges[i].v >> edges[i].w;
//     }

//     BellmanFord(n, edges);
//     return 0;
// }



// method 4
          // chatgpt+BM
          // still give wrong answer 
         

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    long long w;
};

unordered_map<int,list<pair<long long,int>>>graph;

bool bfs(int start,int end){
    if(start==end){
        return true;
    }
    queue<int>q;
    vector<int>visited(end+1,0);
    visited[start]=1;
    q.push(start);
    while(!q.empty()){
        int u =q.front();q.pop();
        for(auto ele:graph[u]){
            if(ele.second==end){
                return true;
            }
            if(!visited[ele.second]){
                visited[ele.second]=1;
                q.push(ele.second);
            }
        }
    }
    if(visited[end]){
        return true;
    }
    return false;
}


void BellmanFord(int n, vector<Edge> &edges) {
    vector<long long> dist(n + 1, LLONG_MIN);
    dist[1] = 0;

    // Relax edges n-1 times
    for (int i = 1; i <= n - 1; i++) {
        for (auto &e : edges) {
            if (dist[e.u] != LLONG_MIN && dist[e.v] < dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Check for positive cycles reachable to the last node
    for (auto &e : edges) {
        if (dist[e.u] != LLONG_MIN && dist[e.v] < dist[e.u] + e.w && bfs(e.v,n)) {              
            cout << -1 << endl;
            return;
        }
    }
    cout << dist[n] << endl;
}



int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int a,b,x;
        cin>>a>>b>>x;
        edges[i].u=a;
        edges[i].v=b;
        edges[i].w=x;
        graph[a].push_back({x,b});
    }

    BellmanFord(n, edges);
    return 0;
}

// if we are finding SSSP then nth relaxation will give -ve cycle
// if we are finding SSLP then nth relaxation will give +ve cyle 



// method 5
        // change SSLP to SSSP
        // by changing the sign of then nodes 


// method 6
        // same as method 4
        // but here we are not doing any bfs or dfs
        // instead we hare alloting dist[i]=infinite if get into the cycle 
        // youtube logic (dardev channel)

// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// #define int long long int
 
// const int INF = 1e17;
// const int NINF = INF*(-1);
 
// struct triplet{
// 	int first;
// 	int second;
// 	int third;
// };
 
// int n, m;	
// vector<triplet> edges;
// vector<int> dist;
 
// void bellman_ford()
// {
// 	for(int i = 1; i < n; ++i)
// 	{
// 		for(auto e: edges)
// 		{
// 			int u = e.first;
// 			int v = e.second;
// 			int d = e.third;
// 			if(dist[u] == INF) continue;
// 			dist[v] = min(dist[v], d+dist[u]);
// 			dist[v] = max(dist[v], NINF);           // this is for setting the floor value that we don't want to make underflow
// 		}
// 	} // n relaxations
 
// 	for(int i = 1; i < n; ++i)                    // n-1 relaxation to propogate the effect of cycle
// 	{
// 		for(auto e: edges)
// 		{
// 			int u = e.first;
// 			int v = e.second;
// 			int d = e.third;
// 			if(dist[u] == INF) continue;
// 			dist[v] = max(dist[v], NINF);
// 			if(dist[u]+d < dist[v])
// 			{
// 				dist[v] = NINF;                    // here is the change in the logic 
// 			}
// 		}
// 	}
// }
 
 
// int32_t main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cin >> n >> m;
// 	dist.resize(n+1);
// 	edges.resize(m);
// 	for(int i = 0; i < m; ++i)
// 	{
// 		struct triplet inp;
// 		cin >> inp.first >> inp.second >> inp.third;
// 		inp.third *= -1; 
// 		edges[i] = inp;
// 	}
 
// 	for(int i = 2; i <= n; ++i)
// 	{
// 		dist[i] = INF;
// 	}
 
// 	bellman_ford();
// 	if(dist[n] == NINF)
// 	{
// 		cout << -1 << endl;
// 		return 0;
// 	} 
// 	cout << dist[n] * (-1) << endl;
// }