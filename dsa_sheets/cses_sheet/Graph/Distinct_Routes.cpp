// method 1
// simple use of dfs and visited map(making node visited which is wrong according to question as we can used same node any no of times)
// BM

// #include<bits/stdc++.h>
// using namespace std;


// unordered_map<int,vector<int>>mp;
// unordered_map<int,int>visited;

// bool dfs(int idx,int n,vector<int>&vec){
//     vec.push_back(idx);
//     if(idx==n){
//         return true;
//     }
//     visited[idx]=1;
//     for(auto it:mp[idx]){
//         if(!visited[it]){
//             if(dfs(it,n,vec)){
//                 return true;
//             }
//         }
//     }
//     vec.pop_back();
//     visited[idx]=0;
//     return false;
// }


// int main(){
//     int n,m;
//     cin>>n>>m;
//     for(int i=0;i<m;i++){
//         int a,b;
//         cin>>a>>b;
//         mp[a].push_back(b);
//     }

//     vector<vector<int>>ans;
//     vector<int>vec;
//     for(auto it:mp[1]){
//         if(!visited[it]){
//             vec.push_back(1);
//             visited[1]=1;
//             if(dfs(it,n,vec)){
//                 ans.push_back(vec);
//             }
//             visited[1]=0;
//         }
//         vec.clear();
//     }
    
//     cout<<ans.size()<<endl;
//     for(int i=0;i<(int)ans.size();i++){
//         cout<<ans[i].size()<<endl;
//         for(int j=0;j<(int)ans[i].size();j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// it fails and it don't give optimised answer 
    // // ex
    // 8 9
    // 1 2
    // 2 3
    // 3 8
    // 1 4
    // 4 5
    // 5 3
    // 2 6
    // 6 7
    // 7 8

    // // expected
    // 2
    // 5
    // 1 2 6 7 8 
    // 5
    // 1 4 5 3 8 

    // // output got
    // 1
    // 4
    // 1 2 3 8 



// method 2
// same as method 1
// but here we are marking edges as visited as in the question 
// given that a edge can be used only once.
// wrong answer(not give optimised answer)
// BM

// #include<bits/stdc++.h>
// using namespace std;


// unordered_map<int,vector<int>>mp;
// unordered_map<int,int>visited;

// bool dfs(int idx,int n,vector<int>&vec){
//     vec.push_back(idx);
//     if(idx==n){
//         return true;
//     }
//     for(auto it:mp[idx]){
//         if(!visited[(it+idx)*(-10000)]){
//             visited[(it+idx)*(-10000)]=1;
//             if(dfs(it,n,vec)){
//                 return true;
//             }
//             visited[(it+idx)*(-10000)]=0;
//         }
//     }
//     vec.pop_back();
//     return false;
// }


// int main(){
//     int n,m;
//     cin>>n>>m;
//     for(int i=0;i<m;i++){
//         int a,b;
//         cin>>a>>b;
//         mp[a].push_back(b);
//     }

//     vector<vector<int>>ans;
//     vector<int>vec;
//     for(auto it:mp[1]){
//         if(!visited[(it+1)*(-10000)]){
//             vec.push_back(1);
//             visited[1]=1;
//             visited[(it+1)*(-10000)]=1;
//             if(dfs(it,n,vec)){
//                 ans.push_back(vec);
//                 visited[1]=0;
//                 continue;
//             }
//             visited[1]=0;
//             visited[(it+1)*(-10000)]=0;
//         }
//         vec.clear();
//     }
    
//     cout<<ans.size()<<endl;
//     for(int i=0;i<(int)ans.size();i++){
//         cout<<ans[i].size()<<endl;
//         for(int j=0;j<(int)ans[i].size();j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


