// method 1
// tle
// memoization


// #include<bits/stdc++.h>
// using namespace std;


// vector<int>dp;
// int esp=1e9+7;
// int no_of_possibility(int x,int n,vector<int>&vec){
//     if(x == 0){
//         return 1;
//     }
//     if(x<0){
//         return 0;
//     }
//     if(dp[x]!=-1){
//         return dp[x];
//     }
//     int val=0;
//     for(int i=0;i<n;i++){
//         val=(val+no_of_possibility(x-vec[i],n,vec))%esp;
//     }
//     return dp[x]=val;
// }

// int main(){
//     int n,x;
//     cin>>n>>x;
//     vector<int>vec(n);
//     for(int i=0;i<n;i++){
//         cin>>vec[i];
//     }
//     dp.resize(x+1,-1);
//     cout<<no_of_possibility(x,n,vec)<<endl;
//     return 0;
// }



// method 2
// iterative
// tle

#include<bits/stdc++.h>
using namespace std;

vector<int>dp;
int esp=1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin>>n>>x;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    dp.resize(x+1,0);
    dp[0]=1;
    for(int i=1;i<=x;i++){                                     // here finding permutation(order matters)
        for(int j=0;j<n;j++){
            if((i-vec[j])>=0){
                dp[i]=(dp[i]+dp[i-vec[j]])%esp;
            }
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}


 