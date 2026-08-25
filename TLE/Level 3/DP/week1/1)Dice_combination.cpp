// method 1
// memoization

// #include<bits/stdc++.h>
// using namespace std;

// int esp=1e9+7;

// vector<int>dp;
// int no_of_ways(int val){
//     if(val<0){
//         return 0;
//     }
//     if(val==0){
//         return 1;
//     }
//     if(dp[val]!=-1){
//         return dp[val];
//     }
//     int value=0;
//     for(int i=1;i<=6;i++){
//         value=(value+no_of_ways(val-i))%esp;
//     }
//     return dp[val]=value;
// }


// int main(){
//     int n;
//     cin>>n;
//     dp.resize(1e6+1,-1);
//     cout<<no_of_ways(n)<<endl;
//     return 0;
// }




// method 2
// iterative version


#include<bits/stdc++.h>
using namespace std;

vector<int>dp;
int esp=1e9+7;
void no_of_ways(int n){
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if((i-j)>=0){
                dp[i]=(dp[i]+dp[i-j])%esp;
            }
        }
    }
    cout<<dp[n]<<endl;
}

int main(){
    int n;
    cin>>n;
    dp.resize(1e6+1,0);
    no_of_ways(n);
    return 0;
}