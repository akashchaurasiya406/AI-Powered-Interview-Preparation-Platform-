// // cf question

// method 1
// memoization 
// Memory limit exceed 



// #include<bits/stdc++.h>
// using namespace std;

// int max_no_of_dolls(int prev,int curr,int& n,vector<int>&vec,vector<vector<int>>&dp){
//     if(curr>n){
//         return 0;
//     }
//     if(dp[curr][prev]!=-1){
//         return dp[curr][prev];
//     }
//     int val=0;
//     if(prev==0){
//         val=max(max_no_of_dolls(prev,curr+1,n,vec,dp),1+max_no_of_dolls(curr,curr+1,n,vec,dp));
//     }
//     else{
//         if(vec[curr]>vec[prev] && curr%prev==0){
//             val=max(max_no_of_dolls(prev,curr+1,n,vec,dp),1+max_no_of_dolls(curr,curr+1,n,vec,dp));
//         }
//         else{
//             val=max_no_of_dolls(prev,curr+1,n,vec,dp);
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
//         vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
//         cout<<max_no_of_dolls(0,1,n,vec,dp)<<endl;
//     }
//     return 0;
// }


// method 2
// same as method 1


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



// method 3
// iterative approach(with 2D )
// gives wrong answer

// #include<bits/stdc++.h>
// using namespace std;


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
//         vector<vector<int>>dp(n+2,vector<int>(2,0));
//         dp[1][1]=1;
//         for(int i=2;i<=n;i++){
//             for(int j=1;j*j<=i;j++){
//                 if(i % j == 0){
//                     int d1 = j;
//                     int d2 = i / j;

//                     if(vec[i] > vec[d1])
//                         dp[i][1] = max(dp[i][1], max(1+dp[d1][0],1 + dp[d1][1]));

//                     if(d1 != d2 && vec[i] > vec[d2])
//                         dp[i][1] = max(dp[i][1], max(1+dp[d2][0],1 + dp[d2][1]));
//                 }
//             }
//             dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
//         }
//         cout<<max(dp[n][0],dp[n][1])<<endl;
//     }
//     return 0;
// }




// method 4
// using the point and i%j==0



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
//             for(int j = 2*i; j <= n; j += i) {
//                 if(a[j] > a[i]) {
//                     dp[j] = max(dp[j], dp[i] + 1);
//                 }
//             }
//             ans = max(ans, dp[i]);
//         }

//         cout << ans << "\n";
//     }
// }



// method 5
// another way to write above code
// TC=O(nsqrt(n))


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n+1), dp(n+1, 1);
        for(int i = 1; i <= n; i++) cin >> a[i];

        int ans = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j*j<=i; j ++) {
                if(i%j!=0)continue;
                if(a[j] < a[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                if(a[i/j]<a[i]){
                    dp[i]=max(dp[i],dp[i/j]+1);
                }
            }
            ans = max(ans, dp[i]);
        }

        cout << ans << "\n";
    }
}

