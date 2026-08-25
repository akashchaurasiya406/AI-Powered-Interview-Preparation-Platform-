// method 1
// include exclude concept of dp
// Memoization
// BM
// TLE

// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<int>>dp;
// int usingdp(int idx,int amount,int n,vector<int>&prices,vector<int>&pages){
//     if(idx>=n || amount<=0){
//         return 0;
//     }
//     if(dp[idx][amount]!=-1){
//         return dp[idx][amount];
//     }

//     int ans=-1e9;
//     // include
//     if(amount>=prices[idx]){
//         ans=max(ans,pages[idx]+usingdp(idx+1,amount-prices[idx],n,prices,pages));
//     }

//     // exlude
//     ans=max(ans,usingdp(idx+1,amount,n,prices,pages));
//     return dp[idx][amount]=ans;
// }


// int main(){
//     int n,x;
//     cin>>n>>x;
//     vector<int>prices(n),pages(n);
//     for(int i=0;i<n;i++){
//         cin>>prices[i];
//     }
//     for(int i=0;i<n;i++){
//         cin>>pages[i];
//     }
//     dp.resize(n+1,vector<int>(x+1,-1));
//     cout<<usingdp(0,x,n,prices,pages);
//     return 0;
// }




// method 2
// Tabulization 
// Bottom up approach 
// Runs


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>prices(n),pages(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));

    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=x;j++){
            int ans=-1;
            if(j>=prices[i]){
                ans=max(ans,pages[i]+dp[i+1][j-prices[i]]);
            }
            ans=max(ans,dp[i+1][j]);
            dp[i][j]=ans;
        }
    }
    cout<<dp[0][x]<<endl;
    return 0;
}



// method 3
// more space optimized 
// see problem tle level 3
