#include<bits/stdc++.h>
using namespace std;
double Me(vector<int>& array1, vector<int>& array2)
    {
        int size=array1.size()+array2.size();
        int n=array1.size();
        int m=array2.size();
        
        int ans=0,prev=0;
        int arr1_i=0,arr2_j=0;
        int z=size/2;
        int count=-1;
        if(size%2!=0){
            while(count!=z && arr1_i<n && arr2_j < m){
            if(array1[arr1_i]<=array2[arr2_j]){
                ans=array1[arr1_i];
                arr1_i++;
                count++;
            }
            else{
                ans=array2[arr2_j];
                arr2_j++;
                count++;
            }
          }
          if(arr1_i==n){
              while(count!=z){
                prev=ans;
                ans=array2[arr2_j];
                arr2_j++;
                count++;
              }
          }
          else if(arr2_j==m){
              while(count!=z){
                prev=ans;
                ans=array1[arr1_i];
                arr1_i++;
                count++;
              }
          }
          return ans;
        }
        else{
            while(count!=z && arr1_i<n && arr2_j < m){
            if(array1[arr1_i]<=array2[arr2_j]){
                prev=ans;
                ans=array1[arr1_i];
                arr1_i++;
                count++;
            }
            else{
                prev=ans;
                ans=array2[arr2_j];
                arr2_j++;
                count++;
            }
          }
          if(arr1_i==n){
              while(count!=z){
                prev=ans;
                ans=array2[arr2_j];
                arr2_j++;
                count++;
              }
          }
          else if(arr2_j==m){
              while(count!=z){
                prev=ans;
                ans=array1[arr1_i];
                arr1_i++;
                count++;
              }
          }
          return (double)(ans+prev)/2;
        }
    }
int main() {
    freopen("input42.txt","r",stdin);
    freopen("output42.txt","w",stdout);
    int n,m;
    cin >> n>>m;
    vector<int> a(n),b(m);
    for (int i = 0; i < n; i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    cout<<Me(a,b)<<endl;
    return 0;
}