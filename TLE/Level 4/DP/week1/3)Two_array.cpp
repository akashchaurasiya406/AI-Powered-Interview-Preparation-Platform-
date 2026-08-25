// method 1
// BM
// dp[i][a][b]=what is the no of arrays which we can create if prev in array 1 is a and that of array 2 is b


#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
vector<vector<vector<int>>>dp;
int solve(int idx,int a,int b,int n,int m){
    if(idx>m)return 0;
    if(dp[idx][a][b]!=-1)return dp[idx][a][b];

    int ans=0;
    for(int i=a+1;i<=n;i++){
        for(int j=i;j<b;j++){
            ans+=(1+solve(idx+1,i,j,n,m))%mod;
            ans%=mod;
        }
    }
    return dp[idx][a][b]=ans;
}


int main(){
    int n,m;
    cin>>n>>m;
    dp.assign(m+1,vector<vector<int>>(n+2,vector<int>(n+2,-1)));
    cout<<solve(1,0,n+1,n,m)<<endl;
    return 0;
}