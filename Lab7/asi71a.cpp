#include<bits/stdc++.h>
using namespace std;
int main(){
     freopen("input71a.txt","r",stdin);
    freopen("output71a.txt","w",stdout);
    int n,W;
    cin>>n>>W;
    float a[n],w[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>w[i];
    vector<pair<float,int>>v;
    for(int i=0;i<n;i++)v.push_back({a[i]/w[i],i});
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=n-1;i>=0;i--){
        int t=v[i].second;
        if(w[i]<=W)ans+=a[i],W-=w[i];
    }
    cout<<ans<<endl;
}