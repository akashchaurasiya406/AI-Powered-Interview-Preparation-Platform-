// just detect the pattern or relation 


// method 1
// BM
// dp[i][j]=no of reflection which we can get if we have i decay time left and j plane are in front of us
//         = dp[i][j-1](front ray)+dp[i-1][n-j](reflected ray)


#include<bits/stdc++.h>
using namespace std;

int mod =1e9+7;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>>dp(k+1,vector<int>(n+1,0));
        for(int i=0;i<=k;i++){
            for(int j=0;j<=n;j++){
                if(i==0){
                    dp[i][j]=0;
                }
                else if(j==0){
                    dp[i][j]=1;
                }
                else{
                    dp[i][j]=(dp[i][j-1]%mod+dp[i-1][n-j]%mod)%mod;
                }
            }
        }
        cout<<dp[k][n]<<endl;
    }
    return 0;
}




