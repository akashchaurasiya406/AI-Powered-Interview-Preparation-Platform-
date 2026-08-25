// method 1
// BM 
// dp[i]=from index i to last is it a part of any sequence or not
// tle
// TC=O(n^2)



// #include<bits/stdc++.h>
// using namespace std;

// vector<int>b;
// vector<int>dp;

// bool solve(int idx, int n){
//     if(idx>=n)return true;

//     if(dp[idx]!=-1)return dp[idx];
    
//     // consider length
//     if(idx+b[idx]<n){
//         bool res=solve(idx+b[idx]+1,n);
//         if(res)return dp[idx]=true;
//     }
//     // consider seq
//     for(int j=idx+1;j<n;j++){                        // extra pre computation 
//         int len=(j-idx);
//         if(b[j]==len){
//             bool res=solve(j+1,n);
//             if(res)return dp[idx]=true;
//         }
//     }
//     return dp[idx]=false;
// }



// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         b.resize(n+1);
//         for(int i=0;i<n;i++){
//             cin>>b[i];
//         }
//         dp.assign(n+1,-1);
//         if(solve(0,n)){
//             cout<<"YES\n";
//         }
//         else{
//             cout<<"NO\n";
//         }
//     }
//     return 0;
// }




// method 2
// BM+chatgpt
// same as method 1
// but with some pre computation 
// as we do b[j]=j-i and if we rearrang it we get  i=j-b[j]
// means i is the index using which we can jump to jth index 



// #include<bits/stdc++.h>
// using namespace std;

// vector<int>b;
// vector<int>dp;
// vector<vector<int>>p;

// bool solve(int idx, int n){
//     if(idx>=n)return true;

//     if(dp[idx]!=-1)return dp[idx];
    
//     // consider length
//     if(idx+b[idx]<n){
//         bool res=solve(idx+b[idx]+1,n);
//         if(res)return dp[idx]=true;
//     }

//     // consider seq
//     // for(int j=idx+1;j<n;j++){                        // removed this extra calcuation 
//     //     int len=(j-idx);
//     //     if(b[j]==len){
//     //         bool res=solve(j+1,n);
//     //         if(res)return dp[idx]=true;
//     //     }
//     // }


//     for(auto it:p[idx]){
//         if(it>idx && it<n){
//             if(solve(it+1,n))return dp[idx]=true;
//         }
//     }
//     return dp[idx]=false;
// }


// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         b.resize(n+1);
//         for(int i=0;i<n;i++){
//             cin>>b[i];
//         }
//         dp.assign(n+1,-1);
//         p.assign(n+1,vector<int>());
//         for(int i=0;i<n;i++){
//             if((i-b[i])>=0)p[i-b[i]].push_back(i);
//         }

//         if(solve(0,n)){
//             cout<<"YES\n";
//         }
//         else{
//             cout<<"NO\n";
//         }
//     }
//     return 0;
// }






// method 3
// sir implmentation 
// set s stores the rechable indexes 



#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        set<int> s;

        // Position before the array starts
        s.insert(-1);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            // Case 1: Take the whole block of length x + 1
            if (s.count(i - 1)) {
                s.insert(i + x);
            }

            // Case 2: Use the sequence condition
            if (s.count(i - x - 1)) {
                s.insert(i);
            }
        }

        // If n-1 is reachable, the whole array can be processed
        if (s.count(n - 1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}


