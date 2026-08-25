// this is the place where is got stuck 
// like:-
       // i) when i think that dfs will be of bool type and the result of the state will be stored in a some DS
       // ii) when i don't know how to handle visited vector and came to know that we don't need an extra dimension for 
       //     storage of state of visited vector on each state of the dp
// see chatgpt solution 



// method 1
// detect cycle first then look for answer 


// method 2
// chatgpt


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<char> vec;
vector<int> state;
vector<vector<int>> dp;

bool hasCycle = false;

vector<int> dfs(int node) {

    // Currently processing -> cycle
    if (state[node] == 1) {
        hasCycle = true;
        return vector<int>(26, 0);
    }

    // Already calculated
    if (state[node] == 2) {
        return dp[node];
    }

    state[node] = 1;

    vector<int> res(26, 0);

    for (int nxt : adj[node]) {

        vector<int> child = dfs(nxt);

        for (int c = 0; c < 26; c++) {
            res[c] = max(res[c], child[c]);
        }
    }

    // Add current node's character
    res[vec[node] - 'a']++;

    state[node] = 2;

    return dp[node] = res;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);

    string s;
    cin >> s;

    vec.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        vec[i] = s[i - 1];
    }

    for (int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    state.assign(n + 1, 0);

    dp.assign(n + 1, vector<int>(26, 0));

    int ans = 0;

    for (int i = 1; i <= n; i++) {

        if (state[i] == 0) {

            vector<int> res = dfs(i);

            if (hasCycle) {
                cout << -1 << '\n';
                return 0;
            }

            for (int c = 0; c < 26; c++) {
                ans = max(ans, res[c]);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}




