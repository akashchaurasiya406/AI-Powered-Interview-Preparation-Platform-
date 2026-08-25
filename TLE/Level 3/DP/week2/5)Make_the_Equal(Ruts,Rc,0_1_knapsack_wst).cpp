// method 1
// BM
// tle
// dp[i][k]=max no of coins which we can get from index i to n if we have k operations left and currently we are at
//          index i
// TC=O(n*k)=O(1e3*1e6)=SC





// method 2
// similar question to 0/1 knapsack 2
// sir
// trick:-
        // it might possible that the will provide constraints value so high that we think we cannot solve it
        // using our state which we have made 
        // some time the parameters value required is less then given in contraints

#include<bits/stdc++.h>
using namespace std;


int n,k;
vector<vector<int>>dp;
vector<int>b,c,req;


int solve(int idx,int k,int n){
    if(idx>=n)return 0;
    
    if(dp[idx][k]!=-1)return dp[idx][k];

    int ans=INT_MIN;
    // no operation
    ans=max(ans,solve(idx+1,k,n));
    // opeartion 
    if(k>=req[b[idx]]){
        ans=max(ans,c[idx]+solve(idx+1,k-req[b[idx]],n));
    }
    return dp[idx][k]=ans;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        b.resize(n+1),c.resize(n+1);
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        for(int i=0;i<n;i++){
            cin>>c[i];
        }
        int N=1e3+1;
        req.resize(N,INT_MAX);
        req[1]=0;
        for(int i=1;i<N;i++){                            // to find min no of moves req to change 1 to i
            for(int j=1;j<=i;j++){
                if((i+i/j)<N){
                    req[i+i/j]=min(req[i+i/j],req[i]+1);
                }
            }
        }
        k=min(k,12*n);                                  // as b value<=1e3 so max operation req to change 
                                                        // b[i] to 1 is 12 so max k can be used is 12*n 
                                                        // n = size of array of b
        dp.assign(n+1,vector<int>(k+1,-1));
        cout<<solve(0,k,n)<<endl;
    }
    return 0;
}



// it migh came in thinking that min no of moves to change 1 to i can be log2(i)
// but it not correct





 