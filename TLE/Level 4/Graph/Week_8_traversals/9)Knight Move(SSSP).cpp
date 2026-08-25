#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    const int N = 1000;

    vector<vector<int>> dist(N + 1, vector<int>(N + 1, -1));

    // 8 possible knight moves
    int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

    queue<pair<int, int>> q;

    // Start from (1,1)
    dist[1][1] = 0;
    q.push({1, 1});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {

            int nx = x + dx[i];
            int ny = y + dy[i];

            // Check whether new position is inside board
            if (nx < 1 || nx > N || ny < 1 || ny > N)
                continue;

            // Already visited
            if (dist[nx][ny] != -1)
                continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    // Answer queries
    while (t--) {
        int a, b;
        cin >> a >> b;

        cout << dist[a][b] << '\n';
    }

    return 0;
}


