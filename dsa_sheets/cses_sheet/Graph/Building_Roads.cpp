// method 1



// #include<bits/stdc++.h>
// using namespace std;

// vector<int>visited;

// void dfs(int node,unordered_map<int,vector<int>>&graph){
//     visited[node]=1;
//     for(auto ele:graph[node]){
//         if(!visited[ele]){
//             dfs(ele,graph);
//         }
//     }
// }

// int main(){
//     int n,m;
//     cin>>n>>m;
//     unordered_map<int,vector<int>>graph;
//     for(int i=0;i<m;i++){
//         int a,b;
//         cin>>a>>b;
//         graph[a].push_back(b);
//         graph[b].push_back(a);
//     }
//     int k=0;
//     vector<pair<int,int>>vec;
//     visited.resize(n+1,0);
//     dfs(1,graph);
//     for(int i=2;i<=n;i++){
//         if(!visited[i]){
//             k++;
//             vec.push_back({1,i});
//             dfs(i,graph);
//         }
//     }
//     cout<<k<<endl;
//     for(int i=0;i<(int)vec.size();i++){
//         cout<<vec[i].first<<" "<<vec[i].second<<endl;
//     }
//     return 0;
// }



// method 2
// another way to write above code
// answer is correct but the road connecting city is wrong 
// i don't know why it is giving wrong answer on submitting 


#include<bits/stdc++.h>
using namespace std;

vector<int>visited;

void dfs(int node,int k,vector<vector<int>>&comp,unordered_map<int,vector<int>>&graph){
    visited[node]=1;
    comp[node]={k,node};
    for(auto ele:graph[node]){
        if(!visited[ele]){
            dfs(ele,k,comp,graph);
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
    int k=0;
    vector<vector<int>>comp(n+1,{-1,-1});
    visited.resize(n+1,0);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i,k,comp,graph);
            k++;
        }
    }
    cout<<k-1<<endl;
    sort(comp.begin(),comp.end());
    for(int i=1;i<n;i++){
        if(comp[i][0]!=comp[i+1][0]){
            cout<<i<<" "<<i+1<<endl;
        }
    }
    return 0;
}