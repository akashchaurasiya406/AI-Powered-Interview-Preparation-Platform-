// method1
// youtube logic
// gives tle=as we are calling bfs1 for each monster which increases the TC

// #include<bits/stdc++.h>
// using namespace std;
// vector<vector<int>>dist;
// string str="";

// int dx[]={-1,1,0,0};
// int dy[]={0,0,-1,1};
// char dir[]={'U','D','L','R'};

// bool check(int& x,int& y,int& n,int& m){
//     if(x<0|| y<0 || x>=n || y>=m){
//         return false;
//     }
//     return true;
// }

// bool bfs(int x,int y,int&n,int& m,vector<string>&grid){
//     if(x==0 || y==0 || x==n-1 || y==m-1){
//         return true;
//     }
//     queue<pair<vector<int>,string>>q;
//     q.push({{x,y,0},""});
//     dist[x][y]=0;
//     while(!q.empty()){
//         pair<vector<int>,string>p=q.front();q.pop();
//         vector<int>vec=p.first;
//         string s=p.second;
//         for(int i=0;i<4;i++){
//             int tempx=vec[0]+dx[i];
//             int tempy=vec[1]+dy[i];
//             int d=vec[2];
//             if(check(tempx,tempy,n,m)&& dist[tempx][tempy]>d+1 && grid[tempx][tempy]!='#'){
//                 if(tempx==0 || tempy==0 || tempx==n-1 || tempy==m-1){
//                     str=s+dir[i];
//                     return true;
//                 }
//                 dist[tempx][tempy]=d+1;
//                 q.push({{tempx,tempy,d+1},s+dir[i]});
//             }
//         }
//     }
//     return false;
// }



// void bfs1(int x,int y,int &n,int&m,vector<string>&grid){
//     queue<pair<int,int>>q;
//     q.push({x,y});
//     dist[x][y]=0;
//     while(!q.empty()){
//         auto [x1,y1]=q.front();q.pop();
//         for(int i=0;i<4;i++){
//             int tempx=x1+dx[i];
//             int tempy=y1+dy[i];
//             if(check(tempx,tempy,n,m) && dist[tempx][tempy]>1+dist[x1][y1] && grid[tempx][tempy]!='#'){
//                 dist[tempx][tempy]=1+dist[x1][y1];
//                 q.push({tempx,tempy});
//             }
//         }
//     }
// }



// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<string>grid(n);
//     for(int i=0;i<n;i++){
//         cin>>grid[i];
//     }
//     dist.resize(n+1,vector<int>(m+1,INT_MAX));
//     int x=-1,y=-1;
//     for(int i=0;i<n;i++){                       // if we not do this then it will give tle
//         for(int j=0;j<m;j++){
//             if(grid[i][j]=='M'){
//                 dist[i][j]=0;
//             }
//             if(grid[i][j]=='A'){
//                 x=i;
//                 y=j;
//             }
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(grid[i][j]=='M'){
//                 bfs1(i,j,n,m,grid);
//             }
//         }
//     }
//     if(bfs(x,y,n,m,grid)){
//         cout<<"YES"<<endl;
//         cout<<str.size()<<endl;
//         cout<<str<<endl;
//     }
//     else{
//         cout<<"NO"<<endl;
//     }
//     return 0;
// }





// method2
// same logic but her we are calling bfs1 only once
// here we first insert the all monsters position first in queue then solve



// #include<bits/stdc++.h>                   // BM=gives tle see why
// using namespace std;
// vector<vector<int>>dist;
// string str="";

// int dx[]={-1,1,0,0};
// int dy[]={0,0,-1,1};
// char dir[]={'U','D','L','R'};

// bool check(int& x,int& y,int& n,int& m){
//     if(x<0|| y<0 || x>=n || y>=m){
//         return false;
//     }
//     return true;
// }

// bool bfs(int x,int y,int&n,int& m,vector<string>&grid){
//     if(x==0 || y==0 || x==n-1 || y==m-1){
//         return true;
//     }
//     queue<pair<vector<int>,string>>q;
//     q.push({{x,y,0},""});
//     dist[x][y]=0;
//     while(!q.empty()){
//         pair<vector<int>,string>p=q.front();q.pop();
//         vector<int>vec=p.first;
//         string s=p.second;
//         for(int i=0;i<4;i++){
//             int tempx=vec[0]+dx[i];
//             int tempy=vec[1]+dy[i];
//             int d=vec[2];
//             if(check(tempx,tempy,n,m)&& dist[tempx][tempy]>d+1 && grid[tempx][tempy]!='#'){
//                 if(tempx==0 || tempy==0 || tempx==n-1 || tempy==m-1){
//                     str=s+dir[i];
//                     return true;
//                 }
//                 dist[tempx][tempy]=d+1;
//                 q.push({{tempx,tempy,d+1},s+dir[i]});
//             }
//         }
//     }
//     return false;
// }



// void bfs1(int &n,int&m,vector<string>&grid){
//     queue<pair<int,int>>q;
//     for(int i=0;i<n;i++){                // if we not do this then it will give tle
//         for(int j=0;j<m;j++){
//             if(grid[i][j]=='M'){
//                 q.push({i,j});
//                 dist[i][j]=0;
//             }
//         }
//     }
//     while(!q.empty()){
//         auto [x1,y1]=q.front();q.pop();
//         for(int i=0;i<4;i++){
//             int tempx=x1+dx[i];
//             int tempy=y1+dy[i];
//             if(check(tempx,tempy,n,m) && dist[tempx][tempy]>1+dist[x1][y1] && grid[tempx][tempy]!='#'){
//                 dist[tempx][tempy]=1+dist[x1][y1];
//                 q.push({tempx,tempy});
//             }
//         }
//     }
// }



// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<string>grid(n);
//     for(int i=0;i<n;i++){
//         cin>>grid[i];
//     }
//     dist.resize(n+1,vector<int>(m+1,INT_MAX));
//     int x=-1,y=-1;
//     for(int i=0;i<n;i++){                   
//         for(int j=0;j<m;j++){
//             if(grid[i][j]=='A'){
//                 x=i;
//                 y=j;
//             }
//         }
//     }
//     bfs1(n,m,grid);
//     if(bfs(x,y,n,m,grid)){
//         cout<<"YES"<<endl;
//         cout<<str.size()<<endl;
//         cout<<str<<endl;
//     }
//     else{
//         cout<<"NO"<<endl;
//     }
//     return 0;
// }







// method 2b
// by chatgpt

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dist;
string str = "";

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

bool check(int &x, int &y, int &n, int &m) {
    if (x < 0 || y < 0 || x >= n || y >= m) {
        return false;
    }
    return true;
}

bool bfs(int x, int y, int &n, int &m, vector<string> &grid) {
    if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
        return true;
    }

    vector<vector<int>> playerDist(n, vector<int>(m, INT_MAX));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> moveDir(n, vector<char>(m, 0));

    queue<pair<int, int>> q;
    q.push({x, y});
    playerDist[x][y] = 0;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        if (cx == 0 || cy == 0 || cx == n - 1 || cy == m - 1) {
            string path;
            while (!(cx == x && cy == y)) {
                path.push_back(moveDir[cx][cy]);
                auto p = parent[cx][cy];
                cx = p.first;
                cy = p.second;
            }
            reverse(path.begin(), path.end());
            str = path;
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (!check(nx, ny, n, m) || grid[nx][ny] == '#')
                continue;
            if (playerDist[nx][ny] != INT_MAX)
                continue;
            // Only move if player reaches before monster
            if (playerDist[cx][cy] + 1 < dist[nx][ny]) {
                playerDist[nx][ny] = playerDist[cx][cy] + 1;
                parent[nx][ny] = {cx, cy};
                moveDir[nx][ny] = dir[i];
                q.push({nx, ny});
            }
        }
    }
    return false;
}

void bfs1(int &n, int &m, vector<string> &grid) {
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        auto [x1, y1] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tempx = x1 + dx[i];
            int tempy = y1 + dy[i];
            if (check(tempx, tempy, n, m) && dist[tempx][tempy] > 1 + dist[x1][y1] && grid[tempx][tempy] != '#') {
                dist[tempx][tempy] = 1 + dist[x1][y1];
                q.push({tempx, tempy});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    dist.assign(n, vector<int>(m, INT_MAX));        

    int x = -1, y = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                x = i;
                y = j;
            }
        }
    }

    bfs1(n, m, grid);

    if (bfs(x, y, n, m, grid)) {
        cout << "YES" << endl;
        cout << str.size() << endl;
        cout << str << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}


