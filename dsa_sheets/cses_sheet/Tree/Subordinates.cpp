#include<bits/stdc++.h>
using namespace std;

vector<int>subordinates;
void dfs(int node,vector<int>adj[]){
    if(adj[node].size()==0){
        subordinates[node]=1;
        return ;
    }
    int ans=1;                 // if we write here 0 then it will given wrong ans
    for(auto child:adj[node]){
        dfs(child,adj);
        ans+=(subordinates[child]);      // here also (1+sub[child]) will give wrong ans
    }
    subordinates[node]=ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>adj[n+1];
    subordinates.resize(n+1,0);
    for(int i=0;i<n-1;i++){
        int u;
        cin>>u;
        adj[u].push_back(i+2);
    }
    dfs(1,adj);
    for(int i=1;i<=n;i++){
        cout<<subordinates[i]-1<<" ";
    }
    cout<<endl;
    return 0;
}


// this question is part of dp on tree 
// as here we are storing the values and reusing it 
// above solution can be written in the way we write for normal dp questions
