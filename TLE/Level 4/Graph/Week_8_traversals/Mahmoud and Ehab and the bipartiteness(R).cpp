#include<bits/stdc++.h>
using namespace std;

unordered_map<int,list<int>>adj;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<pair<int,int>>q;
    int cnt1=0,cnt2=0;
    vector<int>color(n+1);
    q.push({1,-1});
    color[1]=1;
    cnt1++;
    while(!q.empty()){
        auto[node,par]=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(it==par)continue;
            q.push({it,node});
            if(color[node]==1){
                color[it]=2;
                cnt2++;
            }
            else{
                color[it]=1;
                cnt1++;
            }
        }
    }

    long long ans=0;

    // my logic
    // for(int i=1;i<=n;i++){
    //     if(color[i]==1){
    //         ans+=1LL*(cnt2-adj[i].size());
    //     }
    //     else{
    //         ans+=1LL*(cnt1-adj[i].size());
    //     }
    // }
    // cout<<ans/2<<endl;

    // sir logic
    cout<<1LL*cnt1*cnt2-(n-1)<<endl;
    return 0;
}


