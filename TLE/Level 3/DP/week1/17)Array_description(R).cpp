// method 1 
// Memoization 
// BM+chatgpt
// accepted



// #include<bits/stdc++.h>
// using  namespace std;

// int mod=1e9+7;
// vector<vector<int>>dp;

// int usingdp(int idx,int prev,int& n,int& m,vector<int>&vec){
//     if(idx>=n){
//         return 1;
//     }
//     if(dp[idx][prev]!=-1){
//         return dp[idx][prev];
//     }
//     long long int val=0;
//     if(vec[idx]!=0){
//         if(idx==0){
//             val+=usingdp(idx+1,vec[idx],n,m,vec);
//         }
//         else if(abs(vec[idx]-prev)<=1){                           // this is important 
//             val+=usingdp(idx+1,vec[idx],n,m,vec);
//         }
//         val=(val%mod);
//     }
//     else{
//         if(idx==0){
//             for(int i=1;i<=m;i++){
//                 val+=usingdp(idx+1,i,n,m,vec);
//                 val%=mod;
//             }
//         }
//         else{
//             for(int i=max(prev-1,1);i<=min(prev+1,m);i++){                 // imp 
//                 val+=usingdp(idx+1,i,n,m,vec);
//                 val%=mod;
//             }
//         }
//     }
//     return dp[idx][prev]=val;
// }

// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<int>vec(n);
//     for(int i=0;i<n;i++){
//         cin>>vec[i];
//     }
//     dp.resize(n+1,vector<int>(m+1,-1));
//     cout<<usingdp(0,0,n,m,vec)<<endl;
//     return 0;
// }



// method 2
// Tabulization 
// BM






