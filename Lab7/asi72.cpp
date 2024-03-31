#include<bits/stdc++.h>
using namespace std;
int main(){
     freopen("input72.txt","r",stdin);
    freopen("output72.txt","w",stdout);
    int n;
    cin>>n;
    int m[n],d[n];
    for(int i=0;i<n;i++)cin>>m[i];
    for(int i=0;i<n;i++)cin>>d[i];
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)v.push_back({m[i],d[i]});
    sort(v.begin(),v.end());
    set<int>s;
    for(int i=0;i<=n;i++)s.insert(i);
    int ans=0;
    for(int i=n-1;i>=0;i--){
          auto k=s.lower_bound(v[i].second+1);
          k--;
          if(*k)ans+=v[i].first,s.erase(k);
    }
    cout<<ans<<endl;
    
}