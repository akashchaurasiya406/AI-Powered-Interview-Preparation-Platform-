#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>mat,dp;

int main(){
    int n,m;
    cin>>n>>m;
    mat.resize(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    vector<int>children(n+1);
    dp.assign(n+1,vector<int>(1024,0));
    for(int j=0;j<m;j++){
        dp[0][mat[0][j]]=1;
    }
    for(int i=1;i<n;i++){
        for(int k=1;k<1024;k++){
            for(int j=0;j<m;j++){
                if(dp[i-1][k^mat[i][j]]){
                    dp[i][k]=1;
                    children[i-1]=j;
                }
            }
        }
    }
    vector<int>path;
    for(int j=1023;j>0;j--){
        if(dp[n-1][j]){
            int val=j;
            for(int i=1;i<n;i++){
                path.push_back(children[i-1]);
                val=val^mat[i][children[i-1]];
            }
            cout<<"TAK\n";
            for(int j=0;j<m;j++){
                if(mat[0][j]==val){
                    cout<<j+1<<" ";
                    break;
                }
            }
            for(auto it:path)cout<<it+1<<" ";
            cout<<endl;
            return 0;
        }
    }
    cout<<"NIE\n";
    return 0;
}