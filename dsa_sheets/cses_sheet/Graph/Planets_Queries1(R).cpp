
// method 1
// basic dfs 
// gives tle as expected 


// #include<bits/stdc++.h>
// using namespace std;

// unordered_map<int,int>adj;
// // vector<vector<int>>dp;

// int usingdp(int x,int k){
//     if(k==0){
//         return x;
//     }
//     // if(dp[x][k]!=-1){
//     //     return dp[x][k];
//     // }
//     return usingdp(adj[x],k-1);
// }

// int main(){
//     int n,q;
//     cin>>n>>q;
//     for(int i=1;i<=n;i++){
//         int val;
//         cin>>val;
//         adj[i]=val;
//     }
//     // dp.resize(n-1,vector<int>(1e9,-1));                   // size is too large 
//     for(int i=0;i<q;i++){
//         int x,k;
//         cin>>x>>k;
//         cout<<usingdp(x,k)<<endl;
//     }
//     return 0;
// }




// method 2
// give sigterm error as dp is created is that of larg size

// #include<bits/stdc++.h>
// using namespace std;

// unordered_map<int,int>adj;
// vector<vector<int>>dp;

// int usingdp(int x,int k){
//     if(k==0){
//         return x;
//     }
//     if(dp[x][k]!=-1){
//         return dp[x][k];
//     }
//     return dp[x][k]=usingdp(adj[x],k-1);
// }

// int main(){
//     int n,q;
//     cin>>n>>q;
//     for(int i=1;i<=n;i++){
//         int val;
//         cin>>val;
//         adj[i]=val;
//     }
//     dp.resize(n+2,vector<int>(1e9,-1));                   
//     for(int i=0;i<q;i++){
//         int x,k;
//         cin>>x>>k;
//         cout<<usingdp(x,k)<<endl;
//     }
//     return 0;
// }




// method 3
// using the concept of binary lifting 

#include<bits/stdc++.h>
using namespace std;

vector<int>adj;
vector<vector<int>>dp;
// void Binary_Lifting(int node,int k){              // this can stuck in infinite loop if cycle is present
//     dp[node][0]=adj[node];                        // so this code work for tree not for generic graph
//     for(int i=1;i<=k;i++){
//         dp[node][i]=dp[dp[node][i-1]][i-1];
//     }
//     if(adj[node]==node) return;
//     Binary_Lifting(adj[node],k);
//     return ;
// }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,q;
    cin>>n>>q;
    adj.resize(n+1);
    for(int i=1;i<=n;i++){
        int v;
        cin>>v;
        adj[i]=v;
    }
    const int k=log2(1e9)+1;
    dp.resize(n+1,vector<int>(k+1,0));
    for(int i=1;i<=n;i++){
        dp[i][0]=adj[i];
    }
    // Binary_Lifting(1,k);
    for(int j=1;j<=k;j++){
        for(int i=1;i<=n;i++){
            dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }

    while(q--){
        int x,a;
        cin>>x>>a;
        for(int i=0;i<=k;i++){
            if((a>>i)&1){                        // a>>i don't change the a value it only create the temporary value
                x=dp[x][i];
            }
        }
        cout<<x<<'\n';
    }
    return 0;
}



