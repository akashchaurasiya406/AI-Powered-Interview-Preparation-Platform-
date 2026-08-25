// method 1
// using recursive dp


// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<int>>dp;
// int mod=1e9+7;

// int usingdp(int x,int y,int n,vector<string>& str){
//     if(x==n-1 && y==n-1){
//         return 1;
//     }
//     if(dp[x][y]!=-1){
//         return dp[x][y];
//     }
//     // down 
//     int ans=0;
//     if(x+1<n && str[x+1][y]!='*'){
//         ans=(ans+(usingdp(x+1,y,n,str))%mod)%mod;
//     }
//     // right
//     if(y+1<n && str[x][y+1]!='*'){
//         ans=(ans+usingdp(x,y+1,n,str)%mod)%mod;
//     }
//     return dp[x][y]=ans;
// }


// int main(){
//     int n;
//     cin>>n;
//     vector<string>str(n);
//     for(int i=0;i<n;i++){
//         cin>>str[i];
//     }
//     // if start or end blocked
//     if(str[0][0] == '*' || str[n-1][n-1] == '*') {
//         cout << 0;
//         return 0;
//     }
//     dp.resize(n+1,vector<int>(n+1,-1));
//     cout<<usingdp(0,0,n,str);
//     return 0;
// }




// method 2
// iterative approach
// dp[i][j]=number of ways to reach (i,j);


#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;

int main(){
    int n;
    cin>>n;
    vector<string>str(n);
    for(int i=0;i<n;i++){
        cin>>str[i];
    }
    // if start or end blocked
    if(str[0][0] == '*' || str[n-1][n-1] == '*') {
        cout << 0;
        return 0;
    }
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(str[i][j]=='*')dp[i][j]=0;
            else if(i==0 && j==0) dp[i][j]=1;
            else if(i==0)dp[i][j]=dp[i][j-1];
            else if(j==0)dp[i][j]=dp[i-1][j];
            else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            dp[i][j]%=mod;
        }
    }
    cout<<dp[n-1][n-1]<<endl;
    return 0;
}

