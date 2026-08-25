// method 1
// iterative method 
// BM
// solve once more 


// #include<bits/stdc++.h>
// using namespace std;


// int main(){
//     int n;
//     cin>>n;
//     vector<int>vec(n);
//     for(int i=0;i<n;i++){
//         cin>>vec[i];
//     }
//     vector<vector<int>>dp(n+1,vector<int>(1e5+1,0));
//     dp[0][0]=1;                                       // very important 
//     for(int i=1;i<=n;i++){
//         for(int j=0;j<=1e5;j++){
//             if(j==0){
//                 dp[i][j]=1;
//             }
//             else{
//                 // not take 
//                 dp[i][j]=dp[i-1][j];
//                 // take
//                 if((j-vec[i-1])>=0){
//                     dp[i][j]=dp[i-1][j-vec[i-1]] || dp[i-1][j];
//                 }
//             }

//             // only below code will also work 
//             // // not take 
//             // dp[i][j]=dp[i-1][j];
//             // // take
//             // if((j-vec[i-1])>=0){
//             //     dp[i][j]=dp[i-1][j-vec[i-1]] || dp[i-1][j];
//             // }
//         }
//     }

//     vector<int>ans;
//     for(int i=1;i<=1e5;i++){
//         if(dp[n][i])ans.push_back(i);
//     }
//     cout<<ans.size()<<endl;
//     for(auto it:ans){
//         cout<<it<<" ";
//     }
//     cout<<endl;
//     return 0;
// }



