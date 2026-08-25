// method 1
// Binary lifting
// tle 
// BM



// #include<bits/stdc++.h>
// using namespace std;

// vector<int>adj;
// vector<vector<int>>dp;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     int n,q;
//     cin>>n>>q;
//     adj.resize(n+1);
//     dp.resize(n+1,vector<int>(32,-1));
//     for(int i=1;i<=n;i++){
//         int v;
//         cin>>v;
//         adj[i]=v;
//     }

//     for(int i=1;i<=n;i++){
//         dp[i][0]=adj[i];
//     }

//     for(int j=1;j<31;j++){
//         for(int i=1;i<=n;i++){
//             dp[i][j]=dp[dp[i][j-1]][j-1];
//         }
//     }

//     // for(int i=1;i<=n;i++){
//     //     cout<<i<<endl;
//     //     for(int j=0;j<31;j++){
//     //         cout<<dp[i][j]<<" ";
//     //     }
//     //     cout<<'\n';
//     // }

//     cout<<'\n';
//     while(q--){
//         int a,b;
//         cin>>a>>b;
//         if(a==b){
//             cout<<0<<'\n';
//             continue;
//         }
//         int ans=-1;
//         for(int k=1;k<=n;k++){
//             int node=a;
//             for(int i=0;i<=31;i++){
//                 if(k&(1<<i)){
//                     node=dp[node][i];
//                 }
//             }
//             if(node==b){
//                 ans=k;
//                 break;
//             }
//         }
//         cout<<ans<<'\n';
//     }
//     return 0;
// }






// method 2

#include<bits/stdc++.h>
using namespace std;

vector<int>adj;
vector<vector<int>>dp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,q;
    cin>>n>>q;
    adj.resize(n+1);
    dp.resize(n+1,vector<int>(32,-1));
    for(int i=1;i<=n;i++){
        int v;
        cin>>v;
        adj[i]=v;
    }

    for(int i=1;i<=n;i++){
        dp[i][0]=adj[i];
    }

    for(int j=1;j<31;j++){
        for(int i=1;i<=n;i++){
            dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }

    cout<<'\n';
    while(q--){
        int a,b;
        cin>>a>>b;
        if(a==b){
            cout<<0<<'\n';
            continue;
        }
        int ans=-1;
        for(int k=1;k<=n;k++){
            int node=a;
            for(int i=0;i<=31;i++){
                if(k&(1<<i)){
                    node=dp[node][i];
                }
            }
            if(node==b){
                ans=k;
                break;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}