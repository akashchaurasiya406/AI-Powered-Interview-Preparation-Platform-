// code 3:-
         // using bellmanford algo


#include<bits/stdc++.h>
using namespace std;

struct Edges{
    int u,v,w;
};

vector<long long>dist;
vector<int>par;

void Bellmaford(int n,int m,vector<Edges>&edges){
    for(int i=1;i<n;i++){
        for(auto &e:edges){
            if(dist[e.v]>dist[e.u]+e.w){
                dist[e.v]=dist[e.u]+e.w;
                par[e.v]=e.u;
            }
        }
    }
    int x=-1;
    for(auto &e:edges){
        if(dist[e.v]>dist[e.u]+e.w){
            dist[e.v]=dist[e.u]+e.w;        // we also need to add these both lines
            par[e.v]=e.u;
            x=e.v;
            // break             // if we add this it will give wrong answer
        }
    }
    if(x==-1){
        cout<<"NO\n";
    }
    else{
        // move x back n times to be inside the cycle
        for(int i=0;i<n;i++){
            x=par[x];
        }

        vector<int>cycle;
        int curr=x;
        while(true){
            cycle.push_back(curr);
            if(curr==x && cycle.size()>1)break;
            curr=par[curr];
        }
        reverse(cycle.begin(),cycle.end());
        cout<<"YES\n";
        for(int v:cycle){
            cout<<v<<" ";
        }
        cout<<endl;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    vector<Edges>edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }

    dist.assign(n+1,0);          // handle connected components
    par.assign(n+1,-1);
    Bellmaford(n,m,edges);
    return 0;
}






