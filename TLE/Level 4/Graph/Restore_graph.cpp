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
    cout<<ans.size()<<endl;
    for(int l=0;l<(int)ans.size();l++){
        cout<<ans[l].first<<" "<<ans[l].second<<endl;
    }
    return 0;
}

