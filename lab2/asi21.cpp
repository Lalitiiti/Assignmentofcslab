#include<bits/stdc++.h>
using namespace std;
vector<int>merge(vector<int>v1,vector<int>v2,int n,int m){
    vector<int> C;
    int i = 0, j = 0;
    while (i <n && j <m) {
        if(v1[i]<v2[j])C.push_back(v1[i]),i++;
        else C.push_back(v2[j]),j++;
    }
    while (i<n)C.push_back(v1[i]),i++;
    while (j<m)C.push_back(v2[j]),j++;
    return C;
}
vector<int>unione(vector<int>v1,vector<int>v2,int n,int m){
    vector<int>C;
    int i=0,j=0;
    while (i<n&&j<m) {
        if(v1[i]<v2[j])C.push_back(v1[i]),i++;
        else if (v1[i]>v2[j])C.push_back(v2[j]),j++;
        else C.push_back(v1[i]),i++,j++;
    }
    while (i<n)C.push_back(v1[i]),i++;
    while (j<m)C.push_back(v2[j]),j++;
    return C;
}
vector<int>interse(vector<int>v1,vector<int>v2,int n,int m){
    vector<int> C;
    int i = 0, j = 0;
    while (i < n&& j < n) {
         if (v1[i] < v2[j])i++; 
         else if (v1[i] > v2[j])j++;
         else C.push_back(v1[i]),i++,j++;
    }
   return C;
}
void display(vector<int>v){
    for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
    cout<<endl;}
int main(){
    freopen("input21.txt","r",stdin);
    freopen("output21.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int>v1,v2;
    int a;
    for(int i=0;i<n;i++)cin>>a,v1.push_back(a);
    for(int j=0;j<m;j++)cin>>a,v2.push_back(a);
    vector<int>v=merge(v1,v2,n,m);
    display(v);
    v=unione(v1,v2,n,m);
    display(v);
    v=interse(v1,v2,n,m);
    display(v);
    return 0;
}
