// method 1
// BM
// give MLE
// finding all sub array method

// #include<bits/stdc++.h>
// using namespace std;


// int main(){
//     string str;
//     cin>>str;
//     string nums;
//     cin>>nums;
//     int k;
//     cin>>k;
//     int n=str.length();
//     unordered_map<string,int>mp;
//     int ans=0;
//     string val="";
//     int count=0;
//     for(int i=0;i<n;i++){
//         val="";
//         count=0;
//         val+=str[i];
//         if(nums[str[i]-'a']=='0'){
//             count++;
//         }
//         if(count<=k && !mp[val]){
//             ans++;
//             mp[val]++;
//         }
//         for(int j=i+1;j<n;j++){
//             val+=str[j];
//             if(nums[str[j]-'a']=='0'){
//                 count++;
//             }
//             if(count<=k){
//                 if(!mp[val]){
//                     ans++;
//                     mp[val]++;
//                 }
//             }
//             else{
//                 break;
//             }
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }




// solve using creating custome hash function
// method 2
// youtube 



// 2a BM gives wrong answer see why
// #include<bits/stdc++.h>
// using namespace std;


// int main(){
//     string str;
//     cin>>str;
//     string nums;
//     cin>>nums;
//     int k;
//     cin>>k;
//     int n=str.length();
//     long long mod1=1e9+29,mod2=1e9+33;
//     set<pair<long long,long long >>st;
//     long long h1=0,h2=0;
//     int count=0;
//     int pow1=1,pow2=1;
//     int j=0;
//     int i=0;
//     while(i<n){
//         while(count>k){
//             h1=h1-(str[i]-'a'+1)*pow1;
//             h1=h1/26;
//             pow1/=26;
//             h2-=(str[i]-'a'+1)*pow2;
//             h2/=27;
//             pow2/=27;
//             if(nums[str[i]-'a']=='0'){
//                 count--;
//             }
//             i++;
//         }
//         while(j<n){
//             if(nums[str[j]-'a']=='0'){
//                 count++;
//             }
//             if(count<=k){
//                 h1=((h1*26)%mod1+(str[j]-'a'+1))%mod1;
//                 h2=((h2*27)%mod2+(str[j]-'a'+1))%mod2;
//                 st.insert({h1,h1});
//                 pow1*=26;
//                 pow2*=27;
//             }
//             else{
//                 break;
//             }
//             j++;
//         }
//         if(j>=n){
//             while(i<n){
//                 h1=h1-(str[i]-'a'+1)*pow1;
//                 h1=h1/26;
//                 pow1/=26;
//                 h2-=(str[i]-'a'+1)*pow2;
//                 h2/=27;
//                 pow2/=27;
//                 st.insert({h1,h2});
//                 i++;             
//             }
//         }
//     }
//     cout<<st.size()<<endl;
//     return 0;
// }




// 2b youtube same code 
// TLE


#include <bits/stdc++.h>
using namespace std;
#define lli long long

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    string s, bad; 
    cin >> s >> bad;
    lli k; 
    cin >> k;

    int n = s.length();
    const lli mod1 = 1000000007, mod2 = 1000000009;
    const lli base1 = 31, base2 = 37;

    set<pair<lli,lli>> st;

    for (int i = 0; i < n; i++) {
        lli hash1 = 0, hash2 = 0;
        lli pow1 = 1, pow2 = 1;
        int badCount = 0;

        for (int j = i; j < n; j++) {
            if (bad[s[j]-'a'] == '0') badCount++;
            if (badCount > k) break;

            hash1 = (hash1 + (s[j]-'a'+1) * pow1) % mod1;
            hash2 = (hash2 + (s[j]-'a'+1) * pow2) % mod2;

            pow1 = (pow1 * base1) % mod1;
            pow2 = (pow2 * base2) % mod2;

            st.insert({hash1, hash2});
        }
    }

    cout << st.size() << "\n";
    return 0;
}



// write more optimised form of above method 2b
// in which we always don't build hash value from start 
// as i have tried in 2a


