#include<bits/stdc++.h>
using namespace std;
int main(){
     freopen("input71b.txt","r",stdin);
    freopen("output71b.txt","w",stdout);
    int n,W;
    cin>>n>>W;
    int a[n],w[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>w[i];
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++)dp[i][0]=0;
    for(int i=0;i<=W;i++)dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(j>=w[i-1])
          dp[i][j]=max(dp[i][j],dp[i-1][j-w[i-1]]+a[i-1]);
        }
    }
    cout<<dp[n][W]<<endl;
}