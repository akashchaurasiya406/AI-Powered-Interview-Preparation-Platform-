// order matters


// method 2
// memoization
// tle


// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<int>>dp;
// int esp=1e9+7;
// int no_of_possibility(int idx,int x,int n,vector<int>&vec){
//     if(x == 0){
//         return 1;
//     }
//     if(x<0){
//         return 0;
//     }
//     if(dp[x][idx]!=-1){
//         return dp[x][idx];
//     }
//     int val=0;
//     for(int i=idx;i<n;i++){
//         val+=(no_of_possibility(i,x-vec[i],n,vec));
//         if(val>=esp) val-=esp;
//     }
//     return dp[x][idx]=val;
// }

// int main(){
//     int n,x;
//     cin>>n>>x;
//     vector<int>vec(n);
//     for(int i=0;i<n;i++){
//         cin>>vec[i];
//     }
//     dp.resize(x+1,vector<int>(n+1,-1));
//     cout<<no_of_possibility(0,x,n,vec)<<endl;
//     return 0;
// }



// method 2
// iterative
// TC=O(nx) and SC=O(nx)
// dp[i][s]=no of ways to make sum s from using coin i to n

// #include<bits/stdc++.h>
// using namespace std;

// int esp=1e9+7;

// int main(){
//     int n,x;
//     cin>>n>>x;
//     vector<int>vec(n);
//     for(int i=0;i<n;i++)cin>>vec[i];
//     vector<vector<int>>dp(n+1,vector<int>(x+1,0));
//     for(int i=0;i<=n;i++){
//         dp[i][0]=1;
//     }
//     for(int i=n-1;i>=0;i--){                   // coin
//         for(int sum=1;sum<=x;sum++){           // sum
//             // skip
//             int skip=dp[i+1][sum];
//             // pick
//             int pick=0;
//             if(vec[i]<=sum){
//                 pick=dp[i][sum-vec[i]];
//             }
//             dp[i][sum]=(skip+pick)%esp;
//         }
//     }
//     cout<<dp[0][x]<<endl;
//     return 0;
// }




// method 3
// as method 2 have higher SC 
// Space optimized form

// #include<bits/stdc++.h>
// using namespace std;

// int esp=1e9+7;

// int main(){
//     int n,x;
//     cin>>n>>x;
//     vector<int>vec(n);
//     for(int i=0;i<n;i++)cin>>vec[i];
//     vector<vector<int>>dp(2,vector<int>(x+1,0));
//     dp[0][0]=1;
//     dp[1][0]=1;
//     for(int i=n-1;i>=0;i--){
//         dp[1]=dp[0];
//         for(int sum=1;sum<=x;sum++){
//             // skip
//             int skip=dp[1][sum];
//             // pick
//             int pick=0;
//             if(vec[i]<=sum){
//                 pick=dp[0][sum-vec[i]];
//             }
//             dp[0][sum]=(skip+pick)%esp;
//         }
//     }
//     cout<<dp[0][x]<<endl;
//     return 0;
// }




// method 4
// only using 1D dp
// dp[i]=no of ways to make sum i
// logic:-
        // using upto i coin to make sum



#include<bits/stdc++.h>
using namespace std;

int esp=1e9+7;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    vector<int>dp(x+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){                // coins  using upto i coins to make sum form 1 to x
        for(int sum=1;sum<=x;sum++){
            if(vec[i]<=sum){
                dp[sum]=(dp[sum]+[sum-vec[i]])%esp;
            }
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}
