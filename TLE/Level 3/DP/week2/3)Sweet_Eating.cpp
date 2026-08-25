// find the pattern 

// method 1
// BM
// find the pattern(Transition state)


#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    vector<long long>sw(n),ps(n+1);
    for(int i=0;i<n;i++){
        cin>>sw[i];
    }
    sort(sw.begin(),sw.end());
    ps[0]=0;
    for(int i=0;i<n;i++){
        ps[i+1]=ps[i]+sw[i];
    }
    vector<long long>dp(n+1,0);
    for(int i=0;i<m;i++){                          // we can write this inside the below loop as well
        dp[i]=ps[i+1];                             // it will look more clean
    }
    for(int i=m;i<n;i++){
        dp[i]=dp[i-m]+ps[i+1];
    }
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    return 0;
}