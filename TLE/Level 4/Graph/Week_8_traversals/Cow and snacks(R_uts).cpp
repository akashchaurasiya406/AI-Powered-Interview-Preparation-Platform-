// uts=unable to solve 

// logic for each component with V nodes and E edges 
// if(E==(v-1)) no of happy guest =V
// if(E>=V) no of happy guest = V-1 
            // As if E=V in that case a cycle will form due to which 1 person will become upset 
            // therefor the number of cycle in a component the number of upset person and that upset person is the reason of formation of cycle
            // here person =edges and snacks = node


// method 1
// using dfs
// chatgpt


// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> adj;
// vector<int> visited;

// long long nodes;
// long long edges;

// void dfs(int node) {
//     visited[node] = 1;
//     nodes++;

//     for (int next : adj[node]) {
//         edges++;

//         if (!visited[next]) {
//             dfs(next);
//         }
//     }
// }

// int main() {
//     int n, k;
//     cin >> n >> k;

//     adj.resize(n + 1);
//     visited.assign(n + 1, 0);

//     for (int i = 0; i < k; i++) {
//         int u, v;
//         cin >> u >> v;

//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     long long answer = 0;

//     for (int i = 1; i <= n; i++) {
//         if (!visited[i]) {

//             nodes = 0;
//             edges = 0;

//             dfs(i);

//             // Every undirected edge was counted twice
//             edges /= 2;

//             answer += edges - (nodes - 1);
//         }
//     }

//     cout << answer << '\n';

//     return 0;
// }




// method 2
// using DSU
// chatgpt

// the egde which cause formation of cycle that is upset person

#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    // void unite(int a, int b) {
    //     a = find(a);
    //     b = find(b);

    //     if (a == b)
    //         return;

    //     // Union by size
    //     if (size[a] < size[b])
    //         swap(a, b);

    //     parent[b] = a;
    //     size[a] += size[b];
    // }
    
    void unite(int u,int v){
        int ulp_u=find(u);
        int ulp_v=find(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    DSU dsu(n);

    int answer = 0;

    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;

        if (dsu.find(u) == dsu.find(v)) {
            // Adding this edge creates a cycle
            answer++;
        }
        else {
            dsu.unite(u, v);
        }
    }

    cout << answer << '\n';

    return 0;
}