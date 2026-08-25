#include<bits/stdc++.h>
using namespace std;

vector<vector<long long>>dist;
vector<vector<long long>>graph;
void flyod_warshall(int n){
    for(int i=0;i<=n;i++){
        dist[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j && dist[i][k]!=LLONG_MAX && dist[k][j]!=LLONG_MAX){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
}

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    graph.assign(n+1,vector<long long>(n+1,LLONG_MAX));
    dist.assign(n+1,vector<long long>(n+1,LLONG_MAX));
    for(int i=0;i<m;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        graph[a][b]= min(graph[a][b],c);
        graph[b][a]= min(graph[b][a],c);      
        dist[a][b]=graph[a][b];
        dist[b][a]=graph[b][a];
    }

    flyod_warshall(n);
    for(int i=0;i<q;i++){
        int p,q;
        cin>>p>>q;
        if(dist[p][q]!=LLONG_MAX){
            cout<<dist[p][q]<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}