// Concept:-
        // if contraints  are small then we can use
        // dp[i][j]=max values we can get using first i items and sum of weight wt<=j


        // so here we use
        // dp[i][j]=the min amount wt required to get j value by using first i iteams
        // as value range is given less





#include<bits/stdc++.h>
using namespace std;


int  main(){
        long long n,w;
        cin>>n>>w;
        vector<vector<long long>>vec(n+1,vector<long long>(2));
        for(long long i=1;i<=n;i++){
                cin>>vec[i][0]>>vec[i][1];
        }
        vector<vector<long long>>dp(n+1,vector<long long>(1e5+1,1e15));
        dp[0][0]=0;              // this is also important 
        for(long long i=1;i<=n;i++){
                dp[i][0]=0;                                 // this way also we can write base case 
                for(long long j=1;j<=1e5;j++){
                        // not using 
                        dp[i][j]=dp[i-1][j];
                        // using
                        if((j-vec[i][1])>=0){
                                dp[i][j]=min({dp[i][j],vec[i][0]+dp[i-1][j-vec[i][1]]});
                        }
                }
        }
        long long ans=0;
        for(long long j=1;j<=1e5;j++){
                if(dp[n][j]<=w){
                        ans=j;
                }
        }
        cout<<ans<<endl;
        return 0;
}


