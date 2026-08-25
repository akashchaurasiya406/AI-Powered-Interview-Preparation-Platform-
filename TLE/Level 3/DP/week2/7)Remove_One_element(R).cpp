// method 1
// BM
// dp[i][prev][r]=max length of increasin subsequene from index i to last given prev val is prev and 
//                we can remove r elements
// TLE and MLE




// method 2
// BM+chatgpt
// dp[i][r]=max length of subsequence which we get if our subsequence contains i and have r removal left
// gives wrong answr 


// #include<bits/stdc++.h>
// using namespace std;


// int main(){
//     int n;
//     cin>>n;
//     vector<int>vec(n+1);
//     for(int i=0;i<n;i++){
//         cin>>vec[i];
//     }
//     vec[n]=INT_MIN;
//     vector<vector<int>>dp(n+1,vector<int>(2,1));
//     int ans=1;
//     for(int i=n-2;i>=0;i--){
//         for(int j=0;j<2;j++){
//             if(vec[i]<vec[i+1]){
//                 if(j==0)dp[i][j]=1+dp[i+1][j];
//                 else{
//                     // don't skip
//                     dp[i][j]=max(dp[i][j],1+dp[i+1][j]);
//                     // skip
//                     if(vec[i]<vec[i+2]){
//                         dp[i][j]=max(dp[i][j],1+dp[i+2][0]);           // here chatgpt helped 
//                     }
//                 }
//             }
//             else{
//                 if(j==0){
//                     dp[i][j]=1;
//                 }
//                 else{
//                     if(vec[i]<vec[i+2]){                     // here chatgpt helped
//                         dp[i][j]=1+dp[i+2][0];
//                     }
//                 }
//             }
//             ans=max(ans,dp[i][j]);
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }




// method 4
// sir 
// no dp 
// just find the number of sets which are increasing and find the max of 2 connectable sets

// implement it (DR 5 of week 2 dp)


