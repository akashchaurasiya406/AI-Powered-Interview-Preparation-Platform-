// method 1
// BM
// dp[i][j]=means the prob of getting j heads after i coins tosses


// #include<bits/stdc++.h>
// using namespace std;


// int main(){
//     int n;
//     cin>>n;
//     vector<double>vec(n+1);
//     for(int i=0;i<n;i++){
//         cin>>vec[i+1];
//     }
//     vector<vector<double>>dp(n+1,vector<double>(n+1,0.0));
//     dp[0][0]=1;
//     for(int i=1;i<=n;i++){
//         for(int j=0;j<=i;j++){
//             if(j==0){
//                 dp[i][j]=(1-vec[i])*dp[i-1][j];
//                 continue;
//             }
//             // tail
//             dp[i][j]+=((1-vec[i])*dp[i-1][j]);
//             // head 
//             dp[i][j]+=(vec[i]*dp[i-1][j-1]);
//         }
//     }
//     double ans=0.0;
//     for(int i=((n/2)+1);i<=n;i++){
//         ans+=dp[n][i];
//     }
//     cout<<fixed<<setprecision(10)<<ans<<endl;                 // it is important 
//     return 0;
// }




// method 2
// using recursive dp
// BM

#include<bits/stdc++.h>
using namespace std;

vector<vector<double>>dp;

double solve(int idx,int val,int n,vector<double>&vec){
    if(idx>n){
        if(val>=((n/2)+1)){
            return 1;
        }
        return 0;
    }
    if(dp[idx][val]!=-1)return dp[idx][val];
    double ans=0.0;
    // tail
    ans+=(1-vec[idx])*solve(idx+1,val,n,vec);
    // head
    ans+=vec[idx]*solve(idx+1,val+1,n,vec);
    return dp[idx][val]=ans;
}

int main(){
    int n;
    cin>>n;
    vector<double>vec(n+1);
    for(int i=0;i<n;i++){
        cin>>vec[i+1];
    }
    dp.assign(n+1,vector<double>(n+1,-1));
    cout<<fixed<<setprecision(10)<<solve(1,0,n,vec);
    return 0;
}