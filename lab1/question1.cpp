#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("input11.txt","r",stdin);
  freopen("output11.txt","w",stdout);
int n;
cin>>n;
int a[n];
int x=0,y=0;
for(int i=0;i<n;i++){
cin>>a[i];
if(a[i]>=x)y=x,x=a[i];
else if(a[i]>=y)y=a[i];
}
cout<<x+y<<endl;
}
