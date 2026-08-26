//  method 1
// BM
// wrong answer 
// problem in construction of path 



// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<int>>mat,dp;

// int main(){
//     int n,m;
//     cin>>n>>m;
//     mat.resize(n,vector<int>(m));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>mat[i][j];
//         }
//     }
//     vector<int>children(n+1);
//     dp.assign(n+1,vector<int>(1024,0));
//     for(int j=0;j<m;j++){
//         dp[0][mat[0][j]]=1;
//     }
//     for(int i=1;i<n;i++){
//         for(int k=1;k<1024;k++){
//             for(int j=0;j<m;j++){
//                 if(dp[i-1][k^mat[i][j]]){
//                     dp[i][k]=1;
//                     children[i-1]=j;
//                 }
//             }
//         }
//     }
//     vector<int>path;
//     for(int j=1023;j>0;j--){
//         if(dp[n-1][j]){
//             int val=j;
//             for(int i=1;i<n;i++){
//                 path.push_back(children[i-1]);
//                 val=val^mat[i][children[i-1]];
//             }
//             cout<<"TAK\n";
//             for(int j=0;j<m;j++){
//                 if(mat[0][j]==val){
//                     cout<<j+1<<" ";
//                     break;
//                 }
//             }
//             for(auto it:path)cout<<it+1<<" ";
//             cout<<endl;
//             return 0;
//         }
//     }
//     cout<<"NIE\n";
//     return 0;
// }




// method 2
// same as method 1
// BM+chatgpt
//


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mat;
vector<vector<int>> dp;
vector<vector<int>> parent;

int main() {
    int n, m;
    cin >> n >> m;

    mat.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    dp.assign(n, vector<int>(1024, 0));
    parent.assign(n, vector<int>(1024, -1));

    // First row
    for (int j = 0; j < m; j++) {
        int x = mat[0][j];

        dp[0][x] = 1;
        parent[0][x] = j;
    }

    // Remaining rows
    for (int i = 1; i < n; i++) {

        for (int prev = 0; prev < 1024; prev++) {

            if (!dp[i - 1][prev])
                continue;

            for (int j = 0; j < m; j++) {

                int x = prev ^ mat[i][j];

                if (!dp[i][x]) {
                    dp[i][x] = 1;
                    parent[i][x] = j;
                }
            }
        }
    }

    // Find any non-zero XOR
    int target = -1;

    for (int x = 1; x < 1024; x++) {
        if (dp[n - 1][x]) {
            target = x;
            break;
        }
    }

    if (target == -1) {
        cout << "NIE\n";
        return 0;
    }

    cout << "TAK\n";

    vector<int> ans(n);

    int cur = target;

    // Reconstruct from last row
    for (int i = n - 1; i >= 1; i--) {

        int j = parent[i][cur];

        ans[i] = j;

        // Go to previous XOR state
        cur = cur ^ mat[i][j];
    }

    // First row
    ans[0] = parent[0][cur];

    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
    }

    cout << '\n';

    return 0;
}

