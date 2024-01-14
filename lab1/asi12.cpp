#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("input11.txt","r",stdin);
   freopen("output11.txt","w",stdout);
int n;
cin>>n;
int W;
cin>>W;
int w[n],v[n];
for(int i=0;i<n;i++)cin>>w[i];
for(int i=0;i<n;i++)cin>>v[i];
int dp[W+1][n+1];
for(int i=0;i<=W;i++)dp[i][0]=0;
for(int i=0;i<=n;i++)dp[0][i]=0;
for(int i=1;i<=W;i++){
for(int j=1;j<=n;j++){
   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
   if(w[j-1]<=i)dp[i][j]=max(dp[i][j],dp[i-w[j-1]][j-1]+v[j-1]);
}
}
cout<<dp[W][n]<<endl;
}
