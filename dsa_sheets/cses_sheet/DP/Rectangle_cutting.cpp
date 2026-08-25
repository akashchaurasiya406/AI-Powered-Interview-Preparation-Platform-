#include<bits/stdc++.h>
using namespace std;


int main(){
    int a,b;
    cin>>a>>b;
    vector<vector<int>>dp(a+1,vector<int>(b+1,0));
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j) continue;
            else{
                int ans=INT_MAX;
                // horizontal partition 
                for(int r=1;r<i;r++){
                    ans=min({ans,1+dp[r][j]+dp[i-r][j]});
                }
                // vertical partition 
                for(int c=1;c<j;c++){
                    ans=min({ans,1+dp[i][c]+dp[i][j-c]});
                }
                dp[i][j]=ans;
            }
        }
    }
    cout<<dp[a][b]<<endl;
    return 0;
}



