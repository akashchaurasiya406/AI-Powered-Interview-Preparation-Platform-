#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>visited;

bool check(int x,int y,int n,int m){
    if(x>=0 && x<n && y>=0 && y<m){
        return true;
    }
    return false;
}

void dfs(int x,int y,int n,int m,vector<string>&grid){
    visited[x][y]=1;
    // up
    if(check(x-1,y,n,m) && grid[x-1][y]=='.' && !visited[x-1][y]){
        dfs(x-1,y,n,m,grid);
    }
    // down
    if(check(x+1,y,n,m) && grid[x+1][y]=='.' && !visited[x+1][y]){
        dfs(x+1,y,n,m,grid);
    }
    // left
    if(check(x,y-1,n,m) && grid[x][y-1]=='.' && !visited[x][y-1]){
        dfs(x,y-1,n,m,grid);
    }
    // right
    if(check(x,y+1,n,m) && grid[x][y+1]=='.' && !visited[x][y+1]){
        dfs(x,y+1,n,m,grid);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    int count=0;
    visited.resize(n,vector<int>(m,0));
    vector<string>grid(n);
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] =='.' && !visited[i][j]){
                count++;
                dfs(i,j,n,m,grid);
            }
        }
    }
    cout<<count<<endl;
    return 0;
}


