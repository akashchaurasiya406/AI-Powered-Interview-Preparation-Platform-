#include<bits/stdc++.h>
using namespace std;

unordered_map<int,list<pair<int,int>>>adj;

void disj(int n,int k){
    vector<vector<long long>>dist(n+1,vector<long long>(k+1,1e15));
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto[w,u]=pq.top();
        pq.pop();
        if(dist[u][k-1]<w)continue;
        for(auto ele:adj[u]){
            int v=ele.first;
            int c=ele.second;
            if(dist[v][k-1]>c+w){
                dist[v][k-1]=c+w;
                pq.push({dist[v][k-1],v});
                sort(dist[v].begin(),dist[v].end());
            }
        }
    }
    vector<long long>ans;
    for(int i=0;i<k;i++){
        ans.push_back(dist[n][i]);
    }
    for(int i=0;i<k;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    disj(n,k);
    return 0;
}