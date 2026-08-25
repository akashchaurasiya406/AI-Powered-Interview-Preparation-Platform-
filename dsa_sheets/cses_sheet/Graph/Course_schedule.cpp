#include<bits/stdc++.h>
using namespace std;

unordered_map<int,list<int>>adj;
vector<int>indegree;

void topsort(int n){  
    queue<int>tq;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            tq.push(i);
        }
    }   
    vector<int>vec;
    while(!tq.empty()){
        int u=tq.front();
        tq.pop();
        vec.push_back(u);
        for(auto ele:adj[u]){
            indegree[ele]--;
            if(indegree[ele]==0){
                tq.push(ele);
            }
        }
    }
    if(vec.size()==n){
        for(int i=0;i<n;i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    indegree.resize(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    topsort(n);
    return 0;
}