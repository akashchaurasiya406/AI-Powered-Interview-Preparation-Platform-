#include<bits/stdc++.h>
using namespace std;


vector<int>visited,parent;
int dist;

void bfs(int start,int end,unordered_map<int,vector<int>>&graph){
    visited[start]=1;
    queue<pair<int,int>>q;
    q.push({start,1});
    while(!q.empty()){
        auto [x,dis]=q.front();q.pop();
        for(auto ele:graph[x]){
            if(!visited[ele]){
                parent[ele]=x;
                visited[ele]=1;
                q.push({ele,dis+1});
                if(ele==end){
                    dist=dis+1;
                }
            }
        }
    }
}

void findpath(int start,int end){
    vector<int>vec;
    while(start!=end){
        vec.push_back(start);
        start=parent[start];
    }
    vec.push_back(end);
    reverse(vec.begin(),vec.end());
    for(int i=0;i<(int)vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<int>>graph;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    visited.resize(n+1,0);
    parent.resize(n+1,0);
    bfs(1,n,graph);
    if(parent[n]==0){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<dist<<endl;
        findpath(n,1);
    }
    return 0;
}

