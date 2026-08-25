// we cannot say this problem as completly dp problem because we can solve
// this problem just using preffix sum 

#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>dp(n+1,1e9);
    for(int i=1;i<=9;i++){
        dp[i]=1;
    }
    dp[0]=0;
    for(int i=10;i<=n;i++){
        string s=to_string(i);
        int m=s.size();
        vector<int>vec;
        for(int i=0;i<m;i++){
            if(s[i]!='0'){                                          // to avoid infinite loop
                vec.push_back(s[i]-'0');
            }
        }
        int ans=1e9;
        for(int k=0;k<(int)vec.size();k++){
            ans=min(ans,1+dp[i-vec[k]]);
        }
        dp[i]=ans;
    }
    cout<<dp[n]<<endl;
    return 0;
}