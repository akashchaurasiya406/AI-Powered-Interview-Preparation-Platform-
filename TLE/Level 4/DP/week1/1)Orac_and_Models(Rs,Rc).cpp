// method 1
// BM
// dp[i][prev]=max no of models which we can make if we are at current index and prev model which we have taken is at index prev
// MLE


// #include<bits/stdc++.h>
// using namespace std;
// vector<vector<int>>dp;
// int max_no_of_dolls(int prev,int curr,int& n,vector<int>&vec){
//     if(curr>n){
//         return 0;
//     }
//     if(dp[curr][prev]!=-1){
//         return dp[curr][prev];
//     }
//     int val=0;
//     if(prev==0){
//         val=max(max_no_of_dolls(prev,curr+1,n,vec),1+max_no_of_dolls(curr,curr+1,n,vec));
//     }
//     else{
//         if(vec[curr]>vec[prev] && curr%prev==0){
//             val=max(max_no_of_dolls(prev,curr+1,n,vec),1+max_no_of_dolls(curr,curr+1,n,vec));
//         }
//         else{
//             val=max_no_of_dolls(prev,curr+1,n,vec);
//         }
//     }
//     return dp[curr][prev]=val;
// }

// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         vector<int>vec(n+1);
//         for(int i=1;i<=n;i++){
//             cin>>vec[i];
//         }
//         dp.clear();
//         dp.resize(n+2,vector<int>(n+2,-1));
//         cout<<max_no_of_dolls(0,1,n,vec)<<endl;
//     }
//     return 0;
// }





// method 2
// BM
// dp[i]=max no of models which we can have if we are taking model at index i
// conceptual



#include<bits/stdc++.h>
using namespace std;
vector<int>dp;
int max_no_of_dolls(int idx,int& n,vector<int>&vec){
    if(idx>n){
        return 0;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    int val=1;
    for(int i=idx*2;i<=n ;i+=idx){                           // this was imp if we not do this it will give tle
        if(vec[i]>vec[idx] && i%idx==0){
            val=max(val,1+max_no_of_dolls(i,n,vec));
        }
    }
    return dp[idx]=val;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>vec(n+1);
        for(int i=1;i<=n;i++){
            cin>>vec[i];
        }
        dp.assign(n+1,-1);
        int ans=0;
        for(int i=1;i<=n;i++){                              // it is similar to running on multiple sources 
                                                            // similar to finding no of components 
            if(dp[i]==-1){
                ans=max(ans,max_no_of_dolls(i,n,vec));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}





// method 2
// By sir 
// similar to method 2
// another way to write



// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while(t--) {
//         int n;
//         cin >> n;

//         vector<int> a(n+1), dp(n+1, 1);
//         for(int i = 1; i <= n; i++) cin >> a[i];

//         int ans = 1;

//         for(int i = 1; i <= n; i++) {
//             for(int j = 1; j*j<=i; j ++) {
//                 if(i%j!=0)continue;
//                 // first divisor of i 
//                 if(a[j] < a[i]) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//                 // and second divisor or i               // if we not write this here as well it will also work
//                 if(a[i/j]<a[i]){
//                     dp[i]=max(dp[i],dp[i/j]+1);
//                 }
//             }
//             ans = max(ans, dp[i]);
//         }

//         cout << ans << "\n";
//     }
// }

