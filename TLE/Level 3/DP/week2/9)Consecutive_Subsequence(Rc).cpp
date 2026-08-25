// method 1
// BM
// dp[i]=max length which we can get 
// tle


// #include<bits/stdc++.h>
// using namespace std;


// vector<int>num,child;
// unordered_map<int,list<int>>mp;
// vector<int>dp;

// int solve(int idx,int n){
//     // cout<<idx<<" ";
//     if(idx>n)return 0;
//     if(dp[idx]!=-1)return dp[idx];
//     int ans=1;
//     // take
//     for(auto nx:mp[num[idx]+1]){
//         if(nx<=idx)continue;
//         int res=1+solve(nx,n);
//         if(res>ans){
//             ans=res;
//             child[idx]=nx;
//         }
//     }
//     return dp[idx]=ans;
// }


// int main(){
//     int n;
//     cin>>n;
//     num.assign(n+1,0);
//     for(int i=1;i<=n;i++){
//         cin>>num[i];
//     }
//     for(int i=1;i<=n;i++){
//         mp[num[i]].push_back(i);
//     }
//     child.assign(n+1,0);
//     dp.resize(n+1,-1);
//     int ans=0;
//     int start=0;
//     for(int i=1;i<=n;i++){
//         if(dp[i]==-1){
//             int res=solve(i,n);
//             if(res>ans){
//                 ans=res;
//                 start=i;
//             }
//         }
//     }
//     cout<<ans<<endl;
//     while(start!=0){
//         cout<<start<<" ";
//         start=child[start];
//     }
//     cout<<endl;
//     return 0;
// }





// method 2
// sir method 
//



#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    num.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    map<int,int>mp;
    vector<int>dp(n+1,0);
    for(int i=n-1;i>=0;i--){
        dp[nums[i]]=dp[num[i]+1]+1;
    }
    return 0;
}