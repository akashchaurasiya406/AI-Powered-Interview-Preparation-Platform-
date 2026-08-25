#include<bits/stdc++.h>
using namespace std;

vector<long long >dist;

void dijkstra(int start,unordered_map<int,list<pair<long long,int>>>&graph){
    dist[start]=0;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
    pq.push({0,start});
    while(!pq.empty()){
        auto[d,u]=pq.top();pq.pop();
        if(d!=dist[u])continue;           // remove outdated one
        for(auto v:graph[u]){
            if(dist[v.second]>d+v.first){
                dist[v.second]=d+v.first;
                pq.push({dist[v.second],v.second});
            }
        }
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    unordered_map<int,list<pair<long long,int>>>graph;
    for(int i=0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        graph[a].push_back({c,b});
    }
    dist.assign(n+1,LLONG_MAX);
    dijkstra(1,graph);
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}

