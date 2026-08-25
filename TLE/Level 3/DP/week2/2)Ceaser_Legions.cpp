// method 1
// BM
// dp[n1][n2][c1][c2]=no of arrangements if we have n1 footmen left and n2 horsemen left 
                      // c1 footmen standing successively and c2 horsemen successively
// TC=O(n1*n2*c1*c2)=O(100*100*10*10)



// method 2
// sir
// same as method 2
// as we know that only one of n1 and n2 will have some consecutive only and second will have 
// value 0 so instead of storing c1 and c2 store no of successive value and whose value it is

// dp[n1][n2][c][w]=no of arrangement if we have n1 footmen and n2 horsemen left with c successive standing of w
                    // if w=0 means footmen
                    // if w=1 means horsemen
// TC=O(n1*n2*c*w)=O(100*100*10*2)



#include<bits/stdc++.h>
using namespace std;

vector<vector<vector<vector<int>>>>dp;
int n1,n2,k1,k2;
int mod=1e8;

int solve(int f,int h,int c,int t){
    if(f==0 && h==0)return 1;
    if(dp[f][h][c][t]!=-1)return dp[f][h][c][t];

    int ans=0;
    if(t==0){
        // take footment
        if(f>0 && (c+1)<=k1){
            ans+=solve(f-1,h,c+1,0);
            ans%=mod;
        }
        // take horsemen
        if(h>0){
            ans+=solve(f,h-1,1,1);
            ans%=mod;
        }
    }
    else{
        // take footment
        if(f>0){
            ans+=solve(f-1,h,1,0);
            ans%=mod;
        }
        // take horsemen
        if(h>0 && (c+1)<=k2){
            ans+=solve(f,h-1,c+1,1);
            ans%=mod;
        }
    }
    return dp[f][h][c][t]=ans;
}

int main(){
    cin>>n1>>n2>>k1>>k2;
    dp.assign(n1+1,vector<vector<vector<int>>>(n2+1,vector<vector<int>>(max(k1,k2)+1,vector<int>(2,-1))));
    cout<<solve(n1,n2,0,0)<<endl;
    return 0;
}