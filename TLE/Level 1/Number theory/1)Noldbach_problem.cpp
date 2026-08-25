#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,k;
    cin>>n>>k;
    vector<int>prime(n+1,1);
    prime[0]=prime[1]=0;
    for(int i=2;i*i<=n;i++){                       // Sieve of Erathosthenes
        if(prime[i]){
            for(int j=i*i;j<=n;j+=i){            // marking multiples as non-prime
                prime[j]=0;
            }
        }
    }
    vector<int>p;
    for(int i=2;i<=n;i++){
        if(prime[i])p.push_back(i);
    }
    int m=p.size();
    int cnt=0;
    for(int i=0;i<m;i++){
        if(i+1<m && (1+p[i]+p[i+1])<=n && prime[p[i]+p[i+1]+1]){
            cnt++;
        }
    }
    if(cnt>=k)cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}