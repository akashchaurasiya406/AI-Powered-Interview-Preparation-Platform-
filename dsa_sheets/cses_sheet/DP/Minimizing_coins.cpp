#include<bits/stdc++.h>
using namespace std;


int esp=1e9;
vector<int>dp;
int min_no_of_coins(int x,int n,vector<int>&vec){
    if(x==0){
        return 0;
    }
    if(x<0){
        return esp;
    }
    if(dp[x]!=-1){
        return dp[x];
    }
    int val=esp;
    for(int i=0;i<n;i++){
        val=min(val,1+min_no_of_coins(x-vec[i],n,vec));
    }
    return dp[x]=val;
}

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    dp.resize(x+1,-1);
    min_no_of_coins(x,n,vec);
    if(dp[x]==esp){
        cout<<-1<<endl;
    }
    else{
        cout<<dp[x]<<endl;
    }
    return 0;
}