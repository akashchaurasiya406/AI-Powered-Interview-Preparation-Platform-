#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>vec(n+1);
    int cnt=0;
    vec[0]= make_pair(-1,0);
    for(int i=1;i<=n;i++){
        int d;
        cin>>d;
        vec[i]={d,i};
        if(d==0)cnt++;
    }
    if(cnt>1 || cnt<1){
        cout<<-1<<endl;
        return 0;
    }
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    sort(vec.begin(),vec.end());
    vector<pair<int,int>>ans;
    vector<int>degree(n+1,0);
    // unordered_map<int,int>mp;
    // for(int i=1;i<=n;i++){
    //     int d=vec[i].first;
    //     int v=vec[i].second;
    //     if(i==1){
    //         degree[v]=0;
    //         mp[d]=v;
    //     }
    //     else{
    //         if(mp[d-1]==0){
    //             cout<<-1<<endl;
    //             return 0;
    //         }
    //         else{
    //             if(degree[mp[d-1]]>=k){
    //                 cout<<-1<<endl;
    //                 return 0;
    //             }
    //             else{
    //                 int u=mp[d-1];
    //                 ans.push_back({u,v});
    //                 degree[u]++;
    //                 degree[v]++;
    //                 mp[d]=v;
    //             }
    //         }
    //     }
    // }

    int i=1,j=2;
    while(j<=n){
        int u=vec[i].second;
        int d1=vec[i].first;
        int v=vec[j].second;
        int d2=vec[j].first;
        bool insert=true;
        while((d2-d1)==1){
            insert=false;
            cout<<i<<" "<<j<<" "<<degree[u]<<" "<<degree[v]<<endl;;
            if(degree[u]>=k){
                if(vec[i+1].first==d1){
                    cout<<"a\n";
                    u=vec[i].second;
                    ans.push_back({u,v});
                    degree[u]++;
                    degree[v]++;
                }
                else{
                    cout<<-1<<endl;
                    return 0;
                }
            }
            else{
                ans.push_back({u,v});
                degree[u]++;
                degree[v]++;
            }
            j++;
            v=vec[j].second;
            d2=vec[j].first;
        }
        if(insert){
            cout<<-1<<endl;
            return 0;
        }
        i++;
    }
    cout<<ans.size()<<endl;
    for(int l=0;l<(int)ans.size();l++){
        cout<<ans[l].first<<" "<<ans[l].second<<endl;
    }
    return 0;
}

