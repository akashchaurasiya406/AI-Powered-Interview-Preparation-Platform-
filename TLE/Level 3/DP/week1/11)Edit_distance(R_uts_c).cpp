// method 1
// memoization 
// BM


// #include<bits/stdc++.h>
// using namespace std;

// string s1,s2;
// vector<vector<int>>dp;

// int solve(int x,int y,int n1,int n2){
//     if(x>=n1 && y>=n2)return 0;
//     else if(x>=n1) return (n2-y);
//     else if(y>=n2) return (n1-x);

//     if(dp[x][y]!=-1)return dp[x][y];
//     int ans=1e9;
//     if(s1[x]==s2[y])ans=solve(x+1,y+1,n1,n2);
//     else{
//         // add
//         ans=min(ans,1+solve(x,y+1,n1,n2));
//         // remove
//         ans=min(ans,1+solve(x+1,y,n1,n2));
//         // replace
//         ans=min(ans,1+solve(x+1,y+1,n1,n2));
//     }
//     return dp[x][y]=ans;
// }

// int main(){
//     cin>>s1>>s2;
//     int n1=s1.length();
//     int n2=s2.length();
//     dp.assign(n1+1,vector<int>(n2+1,-1));
//     cout<<solve(0,0,n1,n2)<<endl;
//     return 0;
// }




// method 2
// iterative 
// very imp
// uts
// dp[i][j]=min no of operation to make first ith and jth char equal
//

// #include<bits/stdc++.h>
// using namespace std;


// int main(){
//     string s1,s2;
//     cin>>s1>>s2;
//     int n1=s1.length();
//     int n2=s2.length();
//     vector<vector<int>>dp(n1+1,vector<int>(n2+1));
//     for(int i=0;i<=n1;i++){
//         for(int j=0;j<=n2;j++){
//             if(i==0) dp[i][j]=j;
//             else if(j==0) dp[i][j]=i;
//             else if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
//                                   // add  replace remove
//             else dp[i][j]=min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]))+1;
//         }  
//     }
//     cout<<dp[n1][n2]<<endl;
//     return 0;
// }



// concept we can define dp like above also instead of using index used
// length 



// method 3
// dp[i][j]=min no of operation to make string equal upto ith and jth index 
// solve once more 


#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0){
                dp[i][j]=j;
            }
            else if(j==0){
                dp[i][j]=i;
            }
            else if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                int ans=INT_MAX;
                ans=min({ans,1+dp[i][j-1],
                             1+dp[i-1][j],
                             1+dp[i-1][j-1]
                });
                dp[i][j]=ans;
            }
        }
    }
    cout<<dp[n][m]<<"\n";
    return 0;
}



// method 4
// space optimized 