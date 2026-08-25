// bipartite concept
// graph coloring concept

#include<bits/stdc++.h>
using namespace std;

bool val=false;
unordered_map<int,int>mp1,mp2;

void bfs(int start,unordered_map<int,vector<int>>&graph){
    queue<pair<int,int>>q;
    mp1[start]=1;
    q.push({start,1});
    while(!q.empty()){
        auto[x,team]=q.front();q.pop();
        for(auto ele:graph[x]){
            if((team==1 && mp1[ele])||(team==2 && mp2[ele])){
                val=true;
                return ;
            }
            else if((team==1 && mp2[ele]) || (team==2 && mp1[ele])){       // this was important 
                continue;
            }
            if(team==2){
                mp1[ele]=1;
                q.push({ele,1});
            }
            else{
                mp2[ele]=2;
                q.push({ele,2});
            }
        }
    }
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

    for(int i=1;i<=n;i++){
        if(!mp1[i] && !mp2[i]){
            bfs(i,graph);
        }
    }

    if(val){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        for(int i=1;i<=n;i++){
            if(mp1[i]){
                cout<<1<<" ";
            }
            else{
                cout<<2<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}



// above question can be solved in better ways
// code show below 
// by chatgpt

#include <bits/stdc++.h>
using namespace std;

bool val = false;
unordered_map<int, int> color; // 0 = uncolored, 1 = team1, 2 = team2

void bfs(unordered_map<int, vector<int>>& graph, int start) {
    queue<int> q;
    color[start] = 1; // start with team 1
    q.push(start);

    while (!q.empty()) {
        int x = q.front(); q.pop();
        int team = color[x];
        for (auto ele : graph[x]) {
            if (color[ele] == team) {
                val = true; // conflict found
                return;
            }
            if (color[ele] == 0) {
                color[ele] = (team == 1 ? 2 : 1);
                q.push(ele);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // run BFS on all components
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            bfs(graph, i);
        }
    }

    if (val) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            cout << (color[i] == 0 ? 1 : color[i]) << " ";
        }
        cout << endl;
    }
    return 0;
}
