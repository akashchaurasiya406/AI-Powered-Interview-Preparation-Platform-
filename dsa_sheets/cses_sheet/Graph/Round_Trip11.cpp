// code 1:-

// #include<bits/stdc++.h>
// using namespace std;

// unordered_map<int,list<int>>adj;
// vector<int>parent;
// vector<int>visited;
// bool dfs(int start){
//     visited[start]=1;
//     for(auto &ele:adj[start]){
//         if(visited[ele]==2)continue;
//         else if(visited[ele]==1){
//             vector<int>vec;
//             vec.push_back(ele);
//             while(start!=ele){
//                 vec.push_back(start);
//                 start=parent[start];
//             }
//             vec.push_back(ele);
//             reverse(vec.begin(),vec.end());
//             cout<<vec.size()<<endl;
//             for(int i=0;i<(int)vec.size();i++){
//                 cout<<vec[i]<<" ";
//             }
//             cout<<endl;
//             return true;;
//         }
//         else{
//             parent[ele]=start;
//             if(dfs(ele)){
//                 return true;
//             }
//         }
//     }
//     visited[start]=2;
//     return false;
// }

// int main(){
//     int n,m;
//     cin>>n>>m;

//     for(int i=0;i<m;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//     }
//     parent.resize(n+1,-1);
//     visited.resize(n+1,0);
//     bool a=false;
//     for(int i=1;i<=n;i++){
//         if(!visited[i]){
//             if(dfs(i)){
//                 a=true;
//                 break;
//             }
//         }
//     }
//     if(!a){
//         cout<<"IMPOSSIBLE"<<endl;
//     }
//     return 0;
// }




// code 2:-
          // i don't know why commented code gives error

#include<bits/stdc++.h>
using namespace std;

unordered_map<int,list<int>>adj;
vector<int>parent;
vector<int>visited;
bool a = false;
void dfs(int start){
    visited[start]=1;
    for(auto &ele:adj[start]){
        if(visited[ele]==2)continue;
        else if(visited[ele]==1){
            a=true;
            vector<int>vec;
            // vec.push_back(ele);
            // while(start!=ele){
            //     vec.push_back(start);
            //     start=parent[start];
            // }
            // vec.push_back(ele);
            int startnode=ele;
            int endnode=start;
            vec.push_back(startnode);
            while(endnode!=startnode){
                vec.push_back(endnode);
                endnode=parent[endnode];
            }
            vec.push_back(startnode);
            reverse(vec.begin(),vec.end());
            cout<<vec.size()<<endl;
            for(int i=0;i<(int)vec.size();i++){
                cout<<vec[i]<<" ";
            }
            cout<<endl;
            return ;
        }
        else{
            parent[ele]=start;
            dfs(ele);
            if(a){
                return ;
            }
        }
    }
    visited[start]=2;
}

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    parent.resize(n+1,-1);
    visited.resize(n+1,0);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
            if(a){
                break;
            }
        }
    }
    if(a==false){
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}



// code 3:-
        // same as code 2
        // chatgpt


// #include <bits/stdc++.h>
// using namespace std;

// unordered_map<int, vector<int>> adj;
// vector<int> parent, visited;
// bool found = false;
// int cycle_start = -1, cycle_end = -1;

// void dfs(int u) {
//     visited[u] = 1; // visiting
//     for (auto v : adj[u]) {
//         if (visited[v] == 0) {
//             parent[v] = u;
//             dfs(v);
//             if (found) return;
//         } 
//         else if (visited[v] == 1) {
//             // Found a cycle
//             found = true;
//             cycle_end = u;
//             cycle_start = v;
//             return;
//         }
//     }
//     visited[u] = 2; // finished
// }

// int main() {
//     int n, m;
//     cin >> n >> m;

//     for (int i = 0; i < m; i++) {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//     }

//     parent.assign(n + 1, -1);
//     visited.assign(n + 1, 0);

//     for (int i = 1; i <= n; i++) {
//         if (!visited[i]) {
//             dfs(i);
//             if (found) break;
//         }
//     }

//     if (!found) {
//         cout << "IMPOSSIBLE\n";
//     } else {
//         vector<int> cycle;
//         cycle.push_back(cycle_start);
//         for (int v = cycle_end; v != cycle_start; v = parent[v]) {
//             cycle.push_back(v);
//         }
//         cycle.push_back(cycle_start);
//         reverse(cycle.begin(), cycle.end());

//         cout << cycle.size() << "\n";
//         for (int v : cycle) cout << v << " ";
//         cout << "\n";
//     }
//     return 0;
// }
