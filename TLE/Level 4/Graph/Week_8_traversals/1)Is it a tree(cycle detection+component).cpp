#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1;

    for (int nei : adj[node]) {

        // If neighbor is not visited, explore it
        if (!vis[nei]) {
            if (dfs(nei, node, adj, vis))
                return true;
        }

        // If neighbor is already visited and is not parent,
        // then we have found a cycle
        else if (nei != parent) {
            return true;
        }
    }

    return false;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(N + 1, 0);

    // Check cycle
    if (dfs(1, -1, adj, vis)) {
        cout << "NO\n";
        return 0;
    }

    // Check connectivity
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}


