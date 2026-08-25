// // method 1
// // BM 
// // give wrong answer why  


#include<bits/stdc++.h>
using namespace std;

vector<string>o;
unordered_map<char,int>visited;
unordered_map<char,list<int>>adj;
string ans="";


bool dfs(char ch,unordered_map<char,int>&dfsvisited){
    visited[ch]=1;
    dfsvisited[ch]=1;
    bool res=true;
    for(auto it:adj[ch]){
        if(visited[it]){
            if(dfsvisited[it]){
                res=false;
                break;
            }
        }
        else{
            if(!dfs(it,dfsvisited)){
                res=false;
                break;
            }
        }
    }
    ans+=ch;
    dfsvisited[ch]=0;
    return res;
}

int main(){
    int n;
    cin>>n;
    o.resize(n);
    for(int i=0;i<n;i++){
        cin>>o[i];
    }
    for(int p = 0; p <= 100; p++)
    {
        for(int i = 0; i < n - 1; i++)
        {
            if(
                p < o[i].size() &&
                p < o[i + 1].size() &&
                o[i].substr(0, p) == o[i + 1].substr(0, p) &&
                o[i][p] != o[i + 1][p]
            )
            {
                adj[o[i][p]].push_back(o[i + 1][p]);
            }

            if(
                p < o[i].size() &&
                p >= o[i + 1].size() &&
                o[i].substr(0, p) == o[i + 1].substr(0, p)
            )
            {
                cout << "Impossible\n";
                return 0;
            }
        }
    } 
    bool valid=true;
    for(char ch='a';ch<='z';ch++){
        // cout<<"root "<<start[i]<<endl;
        if(!visited[ch]){
            unordered_map<char,int>dfsvisited;
            if(!dfs(ch,dfsvisited)){
                valid=false;
                break;
            }
        }
    }
    if(!valid){
        cout<<"Impossible\n";
    }
    else{
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
    return 0;
}



// method 2
// same logic as method 1
// but different way to implemnt 


