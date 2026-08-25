#include<bits/stdc++.h>
using namespace std;

vector<int>visited,parent;
unordered_map<int,list<int>>graph;
int startnode=-1,endnode=-1;

bool dfs(int u,int p){
    visited[u]=1;
    // cout<<u<<" "<<p<<endl;
    for(auto v:graph[u]){
        if(v==p)continue;
        if(!visited[v]){
            parent[v]=u;
            if(dfs(v,u)){
                return true;
            }
        }
        else{
            endnode=u;
            startnode=v;            // or can add in below for loop
            return true;
        }
    }
    return false;
}


int main(){
    int n,m;
    cin>>n>>m;
    parent.resize(n+1);
    visited.resize(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(dfs(i,-1)){
                // startnode=i;                  can add here also
                break;
            }
        }
    }
    if(startnode==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        vector<int>vec;
        vec.push_back(startnode);
        while(endnode!=startnode){
            vec.push_back(endnode);
            endnode=parent[endnode];
        }
        vec.push_back(startnode);
        reverse(vec.begin(),vec.end());
        cout<<vec.size()<<endl;
        for(int i=0;i<(int)vec.size();i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}