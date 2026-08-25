#include<bits/stdc++.h>
using namespace std;

// method 1
// BM
// TLE

// int main(){
//     string str;
//     cin>>str;
//     int b,s,c;
//     cin>>b>>s>>c;
//     int pb,ps,pc;
//     cin>>pb>>ps>>pc;
//     int r;
//     cin>>r;
//     int n1=0;
//     int n2=0;
//     int n3=0;
//     for(int i=0;i<str.length();i++){
//         if(str[i]=='B'){
//             n1++;
//         }
//         else if(str[i]=='S'){
//             n2++;
//         }
//         else{
//             n3++;
//         }
//     }
//     vector<vector<int>>vec(3,vector<int>(3,INT_MAX));
//     for(int i=0;i<3;i++){
//         if(i==0 && n1!=0){
//             vec[i][0]=b/n1;
//             vec[i][1]=n1-b%n1;
//             vec[i][2]=i;
//         }
//         else if(i==1 && n2!=0){
//             vec[i][0]=s/n2;
//             vec[i][1]=n2-s%n2;
//             vec[i][2]=i;        
//         }
//         else if(i==2 && n3!=0){
//             vec[i][0]=c/n3;
//             vec[i][1]=n3-c%n3;
//             vec[i][2]=i;        
//         }                                
//     }

//     // b,s,c
//     while(r>0){
//         sort(vec.begin(),vec.end());
//         if(vec[0][2]==0 && n1!=0){                     // b
//             if(r>=vec[0][1]*pb){
//                 vec[0][0]++;
//                 r=r-vec[0][1]*pb;
//                 vec[0][1]=n1;
//             }
//             else{
//                 break;
//             }
//         }
//         else if(vec[0][2]==1 && n2!=0){               // s
//             if(r>=vec[0][1]*ps){
//                 vec[0][0]++;
//                 r=r-vec[0][1]*ps;
//                 vec[0][1]=n2;
//             }
//             else{
//                 break;
//             }
//         }
//         else{                                     // c
//             if(r>=vec[0][1]*pc){
//                 vec[0][0]++;
//                 r=r-vec[0][1]*pc;
//                 vec[0][1]=n3;
//             }
//             else{
//                 break;
//             }
//         }    
//     }
//     cout<<vec[0][0]<<endl;
//     return 0;
// }



// method 2
// same code as method 1
// only difference is that here i am using priority_queue instead of vector and sorting





// #define lli long long int;

// int main(){
//     string str;
//     cin>>str;
//     lli b,s,c;
//     cin>>b>>s>>c;
//     lli pb,ps,pc;
//     cin>>pb>>ps>>pc;
//     lli  r;
//     cin>>r;
//     lli n1=0;
//     lli n2=0;
//     lli n3=0;
//     for(int i=0;i<str.length();i++){
//         if(str[i]=='B'){
//             n1++;
//         }
//         else if(str[i]=='S'){
//             n2++;
//         }
//         else{
//             n3++;
//         }
//     }
//     priority_queue<pair<lli,pair<lli ,lli>>,vector<pair<lli,pair<lli,lli>>>,greater<>>pq;
//     for(int i=0;i<3;i++){
//         if(i==0 && n1!=0){
//             pq.push({b/n1,{n1-b%n1,i}});
//         }
//         else if(i==1 && n2!=0){
//             pq.push({s/n2,{n2-s%n2,i}});       
//         }
//         else if(i==2 && n3!=0){
//             pq.push({c/n3,{n3-c%n3,i}});    
//         }
//         else{
//             pq.push({INT_MAX,{INT_MAX,i}});
//         }                               
//     }

//     // b,s,c
//     while(r>0){
//         pair<lli,pair<lli,lli>>p=pq.top();
//         pq.pop();
//         //cout<<r<<" "<<p.first<<" "<<p.second.first<<" "<<p.second.second<<endl;
//         if(p.second.second == 0 && n1!=0){                     // b
//             if(r>=p.second.first*pb){
//                 p.first++;
//                 r=r-p.second.first*pb;
//                 p.second.first=n1;
//                 pq.push(p);
//             }
//             else{
//                 pq.push(p);
//                 break;
//             }
//         }
//         else if(p.second.second == 1 && n2!=0){               // s
//             if(r>=p.second.first*ps){
//                 p.first++;
//                 r=r-p.second.first*ps;
//                 p.second.first=n2;
//                 pq.push(p);
//             }
//             else{
//                 pq.push(p);
//                 break;
//             }
//         }
//         else{                                     // c
//             if(r>=p.second.first*pc){
//                 p.first++;
//                 r=r-p.second.first*pc;
//                 p.second.first=n3;
//                 pq.push(p);
//             }
//             else{
//                 pq.push(p);
//                 break;
//             }
//         }    
//     }
//     pair<lli,pair<lli,lli>>p=pq.top();
//     cout<<p.first<<endl;
//     return 0;
// }



// method 3
