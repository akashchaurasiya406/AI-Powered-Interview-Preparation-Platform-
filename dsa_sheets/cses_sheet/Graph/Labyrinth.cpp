// method1
// dfs with backtracking
// this will give tle or Mle
// as it's TC=O(2^(n*m))
// as here we are finding all possible path from A to B

// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<int>>visited;

// bool check(int x,int y,int n,int m){
//     if(x>=0 && x<n && y>=0 && y<m){
//         return true;
//     }
//     return false;
// }

// void dfs(int x,int y,int n,int m,string val,string& str,vector<string>&grid){
//     if(grid[x][y]=='B'){
//         if(str.length()==0 ||(val.length()<str.length())){
//             str=val;
//         }
//         return ;
//     }
//     visited[x][y]=1;
//     // up
//     if(check(x-1,y,n,m) && (grid[x-1][y]=='.'|| grid[x-1][y]=='B') && !visited[x-1][y]){
//         dfs(x-1,y,n,m,val+'U',str,grid);
//     }
//     // down
//     if(check(x+1,y,n,m) && (grid[x+1][y]=='.' || grid[x+1][y]=='B') && !visited[x+1][y]){
//         dfs(x+1,y,n,m,val+'D',str,grid);
//     }
//     // left
//     if(check(x,y-1,n,m) && (grid[x][y-1]=='.' || grid[x][y-1]=='B') && !visited[x][y-1]){
//         dfs(x,y-1,n,m,val+'L',str,grid);
//     }
//     // right
//     if(check(x,y+1,n,m) && (grid[x][y+1]=='.'|| grid[x][y+1]=='B') && !visited[x][y+1]){
//         dfs(x,y+1,n,m,val+'R',str,grid);
//     }
//     visited[x][y]=0;
// }


// int main(){
//     int n,m;
//     cin>>n>>m;
//     visited.resize(n,vector<int>(m,0));
//     vector<string>grid(n);
//     for(int i=0;i<n;i++){
//         cin>>grid[i];
//     }
//     bool a =false;
//     string str="";
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(grid[i][j] =='A'){
//                 a=true;
//                 string val="";
//                 dfs(i,j,n,m,val,str,grid);
//                 break;
//             }
//         }
//         if(a){
//             break;
//         }
//     }
//     if(str.length()>0){
//         cout<<"YES"<<endl;
//         cout<<str.length()<<endl;
//         cout<<str<<endl;
//     }
//     else{
//         cout<<"NO"<<endl;
//     }
//     return 0;
// }



// method2
// using BFS
// as it is unweighted graph so shortest path 
// can be computed using BFS with 
// TC=O(n*m)
// BM
// here it is giving correct answer but give MLE on platforms
// as we have no implemented BFS efficiently



// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<int>>visited;

// bool check(int x,int y,int n,int m){
//     if(x>=0 && x<n && y>=0 && y<m){
//         return true;
//     }
//     return false;
// }


// string bfs(int x,int y,int n,int m,vector<string>&grid){
//     queue<pair<int,int>>q;
//     vector<vector<string>>vec(n,vector<string>(m,""));
//     vec[x][y]="";
//     q.push({x,y});
//     int dx[]={-1,1,0,0};         // up down left right
//     int dy[]={0,0,-1,1};
//     char dir[]={'U','D','L','R'};
//     while(!q.empty()){
//         auto[x1,y1]=q.front();
//         if(grid[x1][y1]=='B'){
//             return vec[x1][y1];
//         }
//         q.pop();
//         for(int i=0;i<4;i++){
//             int tempx=x1+dx[i];
//             int tempy=y1+dy[i];
//             if(check(tempx,tempy,n,m) && (grid[tempx][tempy]=='.' || grid[tempx][tempy]=='B') && (vec[tempx][tempy].length()==0 ||(vec[x1][y1].length()+1<vec[tempx][tempy].length()))){
//                 vec[tempx][tempy]=vec[x1][y1]+dir[i];
//                 q.push({tempx,tempy});
//             }
//         }
//     }
//     return "";
// }

// int main(){
//     int n,m;
//     cin>>n>>m;
//     visited.resize(n,vector<int>(m,0));
//     vector<string>grid(n);
//     for(int i=0;i<n;i++){
//         cin>>grid[i];
//     }
//     bool a =false;
//     string str="";
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(grid[i][j] =='A'){
//                 a=true;
//                 str=bfs(i,j,n,m,grid);
//                 break;
//             }
//         }
//         if(a){
//             break;
//         }
//     }
//     if(str.length()>0){
//         cout<<"YES"<<endl;
//         cout<<str.length()<<endl;
//         cout<<str<<endl;
//     }
//     else{
//         cout<<"NO"<<endl;
//     }
//     return 0;
// }





// method 3
// using BFS
// by chatgpt
// using parent to track the path


#include <bits/stdc++.h>
using namespace std;

bool check(int x,int y,int n,int m){
    return x>=0 && x<n && y>=0 && y<m;
}

string bfs(int x,int y,int n,int m,vector<string>&grid){
    queue<pair<int,int>>q;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    vector<vector<char>> move(n, vector<char>(m, 0));

    int dx[]={-1,1,0,0};         // up down left right
    int dy[]={0,0,-1,1};
    char dir[]={'U','D','L','R'};

    q.push({x,y});
    dist[x][y] = 0;

    while(!q.empty()){
        auto [x1,y1]=q.front();
        q.pop();

        if(grid[x1][y1]=='B'){
            // reconstruct path
            string path="";
            while(grid[x1][y1] != 'A'){
                path += move[x1][y1];
                auto p = parent[x1][y1];
                x1 = p.first;
                y1 = p.second;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for(int i=0;i<4;i++){
            int tempx=x1+dx[i];
            int tempy=y1+dy[i];
            if(check(tempx,tempy,n,m) && dist[tempx][tempy]==-1 &&
               (grid[tempx][tempy]=='.' || grid[tempx][tempy]=='B')){
                dist[tempx][tempy] = dist[x1][y1] + 1;
                parent[tempx][tempy] = {x1,y1};
                move[tempx][tempy] = dir[i];
                q.push({tempx,tempy});
            }
        }
    }
    return "";
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<string>grid(n);
    for(int i=0;i<n;i++) cin>>grid[i];

    string str="";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] =='A'){
                str=bfs(i,j,n,m,grid);
                break;
            }
        }
        if(!str.empty()) break;
    }

    if(str.length()>0){
        cout<<"YES\n";
        cout<<str.length()<<"\n";
        cout<<str<<"\n";
    } else {
        cout<<"NO\n";
    }
}
