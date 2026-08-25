#include <bits/stdc++.h>
using namespace std;

unordered_map<int,list<int>>adj;
vector<int>visited;

bool dfs(int node,int par){
	visited[node]=1;
	bool ans=true;
	for(auto it:adj[node]){
		if(it==par) continue;
		if(!visited[it])dfs(it,node);
		else ans=false;
	}
	return ans;
}

int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	visited.resize(n+1,0);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			cnt++;
			if(cnt<=1){
				if(!dfs(i,-1)){
					cnt++;
			     	break;			
				}
			}
			else{
				break;
			}
		}
	}
	if(cnt>1)cout<<"NO\n";
	else cout<<"YES\n";
	return 0;
}