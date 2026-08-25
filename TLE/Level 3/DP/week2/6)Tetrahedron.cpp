// method 1
// BM
// MLE:-
      // parent has no use


// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<vector<int>>>dp;

// int mod=1e9+7;

// int solve(int node,int par,int n){
//     if(n<0)return 0;
//     if(n==0){
//         if(node==4)return 1;
//         return 0;
//     }
//     if(dp[node][par][n]!=-1)return dp[node][par][n];
//     int ans=0;
//     for(int i=1;i<=4;i++){
//         if(i==node)continue;
//         // if(i==par){                                    // no requirement of this can go on parent
//         //     if(par==4){
//         //         ans+=solve(i,node,n-1);
//         //         ans%=mod;
//         //     }
//         //     continue;
//         // }
//         // else{
//         //     ans+=solve(i,node,n-1);
//         //     ans%=mod;
//         // }
//         ans+=solve(i,node,n-1);
//         ans%=mod;
//     }
//     return dp[node][par][n]=ans;
// }

// int main(){
//     int n;
//     cin>>n;
//     dp.assign(5,vector<vector<int>>(5,vector<int>(n+1,-1)));
//     cout<<solve(4,0,n);
// }





// method 2
// same as method 1
// MLE:-
      // 


      
// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<int>>dp;

// int mod=1e9+7;

// int solve(int node,int n){
//     if(n<0)return 0;
//     if(n==0){
//         if(node==4)return 1;
//         return 0;
//     }
//     if(dp[node][n]!=-1)return dp[node][n];
//     int ans=0;
//     for(int i=1;i<=4;i++){
//         if(i==node)continue;
//         ans+=solve(i,n-1);
//         ans%=mod;
//     }
//     return dp[node][n]=ans;
// }

// int main(){
//     int n;
//     cin>>n;
//     dp.assign(5,vector<int>(n+1,-1));
//     cout<<solve(4,n);
// }



// method 3
// BM
// iterative approach 
// dp[i][j]=no of ways to reach 4 from index i in j steps


      
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;

int mod=1e9+7;

int main(){
    int n;
    cin>>n;
    dp.assign(5,vector<int>(n+1,0));
    dp[4][0]=1;
    dp[4][1]=0;
    dp[3][1]=1;
    dp[2][1]=1;
    dp[1][1]=1;
    for(int j=2;j<=n;j++){
        for(int i=1;i<=4;i++){
            for(int k=1;k<=4;k++){
                if(k==i)continue;
                dp[i][j]+=dp[k][j-1];
                dp[i][j]%=mod;
            }
        }
    }
    cout<<dp[4][n]<<endl;
    return 0;
}


