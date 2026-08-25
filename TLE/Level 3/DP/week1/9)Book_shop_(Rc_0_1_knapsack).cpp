// 0/1 knapsack problem 
// method 1
// iterative 
// BM
// dp[i][x]=max number of pages which we can by from books present in between the 
//          index 0 and i with price x
// using 2D
// MLE 
// as using 2D matrix


// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n,x;
//     cin>>n>>x;
//     vector<int>price(n);
//     for(int i=0;i<n;i++){
//         cin>>price[i];
//     }
//     vector<int>pages(n);
//     for(int i=0;i<n;i++){
//         cin>>pages[i];
//     }
//     vector<vector<int>>dp(n+1,vector<int>(x+1,0));

//     for(int j=price[0];j<=x;j++){
//         dp[0][j]=pages[0];
//     }
//     for(int i=1;i<n;i++){                                            // we cannot 1 book more then once so that's
//                                                                      // book index loop is outside to that of price loop
//         for(int val=1;val<=x;val++){ 
//             if(val>=price[i]){
//                 dp[i][val]=(pages[i]+dp[i-1][val-price[i]]);
//             }
//             dp[i][val]=max(dp[i][val],dp[i-1][val]);
//         }
//     }
//     cout<<dp[n-1][x]<<endl;
//     return 0;
// }




// method 2
// BM
// using space optimized as 
// dp[i] only depends on dp[i-1]
// Accepted 
// 

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n,x;
//     cin>>n>>x;
//     vector<int>price(n);
//     for(int i=0;i<n;i++){
//         cin>>price[i];
//     }
//     vector<int>pages(n);
//     for(int i=0;i<n;i++){
//         cin>>pages[i];
//     }
//     vector<vector<long long>>dp(2,vector<long long>(x+1,0));

//     for(int j=price[0];j<=x;j++){
//         dp[0][j]=pages[0];
//     }
//     for(int i=1;i<n;i++){                                            // we cannot 1 book more then once so that's
//                                                                      // book index loop is outside to that of price loop
//         for(int val=1;val<=x;val++){ 
//             if(val>=price[i]){
//                 dp[1][val]=(1LL*pages[i]+dp[0][val-price[i]]);
//             }
//             dp[1][val]=max(dp[1][val],dp[0][val]);
//         }
//         dp[0]=dp[1];
//     }
//     cout<<dp[1][x]<<endl;
//     return 0;
// }



// method 3
// using 1D dp
// chatgpt


// dp[val]
         // initally means max pages after using no books 
         // after process 0
         // it is max pages after using upto book 0
// dp[val] = maximum number of pages we can get using the
         //  books processed so far, with a maximum budget of val. 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> price(n);
    vector<int> pages(n);

    for (int i = 0; i < n; i++)
        cin >> price[i];

    for (int i = 0; i < n; i++)
        cin >> pages[i];

    vector<long long> dp(x + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int val = x; val >= price[i]; val--) {
            dp[val] = max(
                dp[val],
                1LL * pages[i] + dp[val - price[i]]
            );
        }
    }

    cout << dp[x] << endl;
}


