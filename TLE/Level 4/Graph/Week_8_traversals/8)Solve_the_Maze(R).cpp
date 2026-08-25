
// method 1
// tle 


// #include<bits/stdc++.h>
// using namespace std;

// vector<string>s;
// vector<vector<int>>vis;
// int dx[]={-1,1,0,0};
// int dy[]={0,0,-1,1};


// bool dfs(int x,int y,int n,int m){
//     if(x==n-1 && y==m-1){
//         if(s[x][y]=='#')return false;
//         return true;
//     }
//     bool ans=false;
//     vis[x][y]=1;
//     for(int i=0;i<4;i++){
//         int nx=x+dx[i];
//         int ny=y+dy[i];
//         if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && s[nx][ny]!='#'){
//             if(dfs(nx,ny,n,m)){
//                 ans=true;
//             }
//         }
//     }
//     return ans;
// }

// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n,m;
//         cin>>n>>m;
//         s.resize(n);
//         for(int i=0;i<n;i++){
//             cin>>s[i];
//         }
//         bool ans=true;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(s[i][j]=='B'){
//                     for(int k=0;k<4;k++){
//                         int nx=i+dx[k];
//                         int ny=j+dy[k];
//                         if(nx>=0 && nx<n && ny>=0 && ny<m){
//                             if(s[nx][ny]=='.'){
//                                 s[nx][ny]='#';
//                             }
//                             else if(s[nx][ny]=='G'){
//                                 ans=false;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         if(!ans){
//             cout<<"No\n";
//             continue;
//         }
//         int cnt=0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(s[i][j]=='G'){
//                     vis.assign(n,vector<int>(m,0));
//                     if(!dfs(i,j,n,m)){
//                         ans=false;
//                         break;
//                     }
//                     cnt++;
//                 }
//             }
//             if(!ans)break;
//         }
//         if(s[n-1][m-1]=='#'){
//             if(cnt)ans=false;
//         }
//         if(ans){
//             cout<<"Yes";
//         }
//         else{
//             cout<<"No";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// method 2 
// same as method 1 but with slight change
// gives Tle


// #include<bits/stdc++.h>
// using namespace std;

// vector<string>s;
// int dx[]={-1,1,0,0};
// int dy[]={0,0,-1,1};


// bool dfs(int x,int y,int n,int m,vector<vector<int>>&vis){
//     if(x==n-1 && y==m-1){
//         if(s[x][y]=='#')return false;
//         return true;
//     }
//     bool ans=false;
//     vis[x][y]=1;
//     for(int i=0;i<4;i++){
//         int nx=x+dx[i];
//         int ny=y+dy[i];
//         if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && s[nx][ny]!='#'){
//             if(dfs(nx,ny,n,m,vis)){
//                 ans=true;
//             }
//         }
//     }
//     return ans;
// }

// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n,m;
//         cin>>n>>m;
//         s.resize(n);
//         for(int i=0;i<n;i++){
//             cin>>s[i];
//         }
//         bool ans=true;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(s[i][j]=='B'){
//                     for(int k=0;k<4;k++){
//                         int nx=i+dx[k];
//                         int ny=j+dy[k];
//                         if(nx>=0 && nx<n && ny>=0 && ny<m){
//                             if(s[nx][ny]=='.'){
//                                 s[nx][ny]='#';
//                             }
//                             else if(s[nx][ny]=='G'){
//                                 ans=false;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         if(!ans){
//             cout<<"No\n";
//             continue;
//         }
//         int cnt=0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(s[i][j]=='G'){
//                     vector<vector<int>>vis(n,vector<int>(m,0));
//                     if(!dfs(i,j,n,m,vis)){
//                         ans=false;
//                         break;
//                     }
//                     cnt++;
//                 }
//             }
//             if(!ans)break;
//         }
//         if(s[n-1][m-1]=='#'){
//             if(cnt)ans=false;
//         }
//         if(ans){
//             cout<<"Yes";
//         }
//         else{
//             cout<<"No";
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// method 3
// chatgpt

// #include <bits/stdc++.h>
// using namespace std;

// int n, m;
// vector<string> grid;
// vector<vector<bool>> visitedBad;
// vector<vector<bool>> reachable;

// int dx[4] = {-1, 1, 0, 0};
// int dy[4] = {0, 0, -1, 1};

// bool isValid(int row, int col) {
//     return row >= 0 && row < n && col >= 0 && col < m;
// }

// void dfsBadComponent(int row, int col) {
//     visitedBad[row][col] = true;

//     for (int direction = 0; direction < 4; direction++) {
//         int nextRow = row + dx[direction];
//         int nextCol = col + dy[direction];

//         if (!isValid(nextRow, nextCol)) {
//             continue;
//         }

//         if (grid[nextRow][nextCol] == '.') {
//             grid[nextRow][nextCol] = '#';
//         }

//         if (grid[nextRow][nextCol] == 'B' &&
//             !visitedBad[nextRow][nextCol]) {
//             dfsBadComponent(nextRow, nextCol);
//         }
//     }
// }

// bool solve() {
//     visitedBad.assign(n, vector<bool>(m, false));

//     for (int row = 0; row < n; row++) {
//         for (int col = 0; col < m; col++) {
//             if (grid[row][col] == 'B' && !visitedBad[row][col]) {
//                 dfsBadComponent(row, col);
//             }
//         }
//     }

//     reachable.assign(n, vector<bool>(m, false));
//     queue<pair<int, int>> bfsQueue;

//     if (grid[n - 1][m - 1] != '#') {
//         bfsQueue.push({n - 1, m - 1});
//         reachable[n - 1][m - 1] = true;
//     }

//     while (!bfsQueue.empty()) {
//         auto [row, col] = bfsQueue.front();
//         bfsQueue.pop();

//         for (int direction = 0; direction < 4; direction++) {
//             int nextRow = row + dx[direction];
//             int nextCol = col + dy[direction];

//             if (!isValid(nextRow, nextCol)) {
//                 continue;
//             }

//             if (reachable[nextRow][nextCol]) {
//                 continue;
//             }

//             if (grid[nextRow][nextCol] == '#') {
//                 continue;
//             }

//             reachable[nextRow][nextCol] = true;
//             bfsQueue.push({nextRow, nextCol});
//         }
//     }

//     for (int row = 0; row < n; row++) {
//         for (int col = 0; col < m; col++) {
//             if (grid[row][col] == 'G' && !reachable[row][col]) {
//                 return false;
//             }

//             if (grid[row][col] == 'B' && reachable[row][col]) {
//                 return false;
//             }
//         }
//     }

//     return true;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int testCases;
//     cin >> testCases;

//     while (testCases--) {
//         cin >> n >> m;

//         grid.resize(n);

//         for (int row = 0; row < n; row++) {
//             cin >> grid[row];
//         }

//         cout << (solve() ? "Yes" : "No") << '\n';
//     }

//     return 0;
// }




// method 4
// if adjacent G and B the answer will be false 
// after we block all path of B
// and the we start from (n-1,m-1) and travese to the place
// upto which it is visited and then
// check whether all G are visited and all B not visited if this happens 
// in that case we will return Yes else No

// code yourself nextime


