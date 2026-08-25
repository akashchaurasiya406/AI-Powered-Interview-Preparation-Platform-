// method 1
// BM
// dp[i][k][prev]=min amount of time taken to move from ith position to last position 
                 // provide we can remove max k dists and the prev dist which is not removed
                 // is prev
                 
                 // no of state =1e5*500*500 
                 // it will give tle and mle


// method 2
// dp[i][k][prev]=min amount time req to move from ith dist to nth dist provide we can remove 
                  // k dist and prev dist which is not removed is prev
                  // we will add one dummy dist at end to make calculation easy
                  
                  // no of state =500*500*500=1e8
                  // it will not give tle but it will give mle
                  // TC=O(n^3) and SC=O(n^3)   where n=500
                  // we can solve this using space optimization 
                  // And 
                  // we will be able to solve if we decrease the number of states and increase the Transition Time(TT)
                  

// method 3
// dp[i][k]=min time req to move from ith dist to nth dist provided we can remove k dists and we are 
            // not removing ith dist
            // using this we have removed the use of prev variable

            // Tc=O(n^3) but SC=O(n^2) and TT=O(n)     where n=500


#include<bits/stdc++.h>
using namespace std;


vector<int>dist,speed;
vector<vector<int>>dp;

int solve(int idx,int k,int n){
    if(idx>=n)return 0;

    if(dp[idx][k]!=-1)return dp[idx][k];
    int ans=INT_MAX;
    for(int i=idx+1;i<=n;i++){
        if(i-(idx+1)<=k){
            ans=min(ans,speed[idx]*(dist[i]-dist[idx])+solve(i,k-(i-idx-1),n));
        }
    }
    return dp[idx][k]=ans;
}


int main(){
    int n,l,k;
    cin>>n>>l>>k;
    dist.resize(n+1),speed.resize(n+1);
    for(int i=0;i<n;i++){
        cin>>dist[i];
    }
    dist[n]=l;
    for(int i=0;i<n;i++){
        cin>>speed[i];
    }

    dp.assign(n+1,vector<int>(n+1,-1));
    cout<<solve(0,k,n);
}
                  
 
                  
