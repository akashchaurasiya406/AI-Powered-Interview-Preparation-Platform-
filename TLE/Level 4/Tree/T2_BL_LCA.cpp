// CONCEPT 1
           // BINARY LIFTING

// Q1
// find kth parent of a node:-
                            // solve using parent in dfs can solve 
                            // Tc=O(n)

// Q2
// same find kth parent of a node but for q queries given 
            // i) Above Brute force give TLE(Dfs+parent) as TC=O(q*n)
            // ii) Binary Lifting method 
            
            
// Concept 
// Binary Lifting:-
                // every integer can be written as sum of power of 2.
                // so we store the 2th power parents of node 
                // as 1st par,2nd par,4th par,8th par,.....
                // so when we asked for 11th par we can find it directly by jumping
                // to 8th par then 2nd par of 8th par and then 1st par of 2nd par
                // Binary lifting for k-th ancestor works only when there is a unique path from the root to every node.
                // or graph need to be functional graph or Tree

            
// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<int>>parent,adj;

// void dfs(int node,int par,int k){
//     parent[node][0]=par;
//     for(int i=1;i<=k;i++){
//         parent[node][i]=parent[parent[node][i-1]][i-1];
//     }

//     for(auto it:adj[node]){
//         if(it==par)continue;
//         dfs(it,node,k);
//     }
// }

// int main(){
//     int n;
//     cin>>n;
//     adj.resize(n+1);
//     for(int i=0;i<n-1;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     // node is from 1 to n
//     int k=log2(n)+1;
//     parent.resize(n+1,vector<int>(k+1,0));
//     dfs(1,0,k);       // node,par,kth_ancestor

//     int q;
//     cin>>q;
//     while(q--){
//         int node,k;
//         cin>>node,k;
//         int cnt=0;
//         while(k){
//             if(k&1){
//                 node=parent[node][cnt];
//                 if(node==0){
//                     break;
//                 }
//             }
//             cnt++;
//             k=k>>1;
//         }
//         cout<<node<<endl;
//     }
//     return 0;
// }



// parent[node][0] = 1st ancestor
// parent[node][1] = 2nd ancestor
// parent[node][2] = 4th ancestor
// parent[node][3] = 8th ancestor



// Parent array given → no DFS/BFS needed.
// Undirected tree given as edges → DFS or BFS is required to determine parents before binary lifting.

// another version if 
// parent node is given 

// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     int LOG = 20;   // enough for n <= 1e6

//     vector<vector<int>> up(n + 1, vector<int>(LOG + 1, 0));

//     // input direct parent of every node
//     // root's parent = 0
//     for(int i = 1; i <= n; i++) {
//         cin >> up[i][0];
//     }

//     for(int j = 1; j <= LOG; j++) {
//         for(int i = 1; i <= n; i++) {
//             up[i][j] = up[ up[i][j-1] ][j-1];
//         }
//     }
//     int q;
//     cin >> q;
//     while(q--) {
//         int node, k;
//         cin >> node >> k;
//         for(int i = 0; i <= LOG; i++) {
//             if(k & (1 << i)) {
//                 node = up[node][i];
//                 if(node == 0) break;
//             }
//         }
//         cout << node << "\n";
//     }
//     return 0;
// }




// CONCEPT 2
           // LOWEST COMMON ANCESTOR 


// Method 1:-
            // Brute force:-
                        // for a and b
                        // find the path from root to a and from root to b
                        // the point from where path start looking similar if we traverse from a to root
                        // and from b to root then that node is the LCA
                        // find path:-
                                    // using dfs and parent vector 
                        // Then travese through the path from and a and b to find first common node 
                        // or can traveser from root to a and root to b and the place where we get diff node 
                        // path path the prev of that node will be the LCA
                        // TC=O(n)
                        // Soln:-
                                // bool dfs(TreeNode* root,TreeNode*p,vector<TreeNode*>&par){
                                //     if(root==nullptr){
                                //         return false;
                                //     }
                                //     if(root->val==p->val){
                                //         par.push_back(root);
                                //         return true;
                                //     }
                                //     par.push_back(root);
                                //     if(root->left!=nullptr){
                                //         bool ans=dfs(root->left,p,par);
                                //         if(ans){
                                //             return true;
                                //         }
                                //     }
                                //     if(root->right!=nullptr){
                                //         bool ans=dfs(root->right,p,par);
                                //         if(ans){
                                //             return true;
                                //         }
                                //     }
                                //     par.pop_back();
                                //     return false;
                                // }

                                // TreeNode* lowestcommon(TreeNode* root,TreeNode* p,TreeNode* q ){
                                //     vector<TreeNode*>par1,par2;
                                //     dfs(root,p,par1);
                                //     dfs(root,q,par2);
                                //     int n=par1.size();
                                //     int m=par2.size();
                                //     int i=0,j=0;
                                //     TreeNode* ans=root;
                                //     while(i<n && j<m){
                                //         if(par1[i]->val!=par2[j]->val){
                                //             if(i-1>=0){
                                //                 ans=par1[i-1];
                                //             }
                                //             break;
                                //         }
                                //         ans=par1[i];
                                //         i++,j++;
                                //     }
                                //     return ans;
                                // }

// Method 2:-
          // Brute force:-
                       // using dfs but with no parent 
                       // very good solution 
                       // TC=O(n)
                       // solution:-
                                // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
                                //     if(root==NULL || root==p || root==q){
                                //         return root;
                                //     }
                                //     TreeNode* left=lowestCommonAncestor(root->left,p,q);
                                //     TreeNode* right=lowestCommonAncestor(root->right,p,q);
                                //     if(left==NULL){
                                //         return right;
                                //     }
                                //     if(right==NULL){
                                //         return left;
                                //     }
                                //     else{
                                //         return root;
                                //     }

                                // }                       

// Method 3:-
           // Steps:-
                   // i) Bring them(a,b) to the same level using Binary lifting 
                   //    both levels =min(level_a,level_b)
                                // suppose level_b>level_a then let k=(level_b-level_a)
                                // Then find the kth ancestor of b let it be c
                   //    Now find the common ancestor between (a,c)
                   
                   // ii) Move a and c to every unequal node(16 to 0) 
                   //     Means start from 2^16 ancestor to 2^0 ancestor 
                   //     move from 16 to 0 till we get same node and 
                   //     the place where we get diff node from their we from from ancestor 1 to 16
                   //     and the place where we get same node will be our answer


#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int par,vector<int>adj[],vector<vector<int>>&dp,vector<int>&level,int l=0){
    dp[node][0]=par;
    level[node]=l;
    for(int i=1;i<=16;i++){
        dp[node][i]=dp[dp[node][i-1]][i-1];
    }
    for(auto it:adj[node]){
        if(it==par)continue;
        dfs(it,node,adj,dp,level,l+1);
    }
}

int getKpar(int node,int k,vector<vector<int>>&dp){
    for(int i=16;i>=0;i--){
        if((k>>i)&1){
            node=dp[node][i];
        }
    }
    return node;
}


int main(){
    int n;
    cin>>n;
    vector<int>adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>>dp(n+1,vector<int>(17,0));
    vector<int>level(n+1,0);
    dfs(1,0,adj,dp,level,0);

    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        if(level[a]>level[b]){
            swap(a,b);
        }
        // now a is guranted that it is at lower level
        int k=level[b]-level[a];
        // make b to the same level as a
        b=getKpar(b,k,dp);
        if(a==b){
            cout<<a<<endl;
            continue;
        }
        for(int i=16;i>=0;i--){
            if(dp[a][i]!=dp[b][i]){
                a=dp[a][i];
                b=dp[b][i];
            }
        }
        cout<<dp[a][0]<<endl;
    }
    return 0;
}









