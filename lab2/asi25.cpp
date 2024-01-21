#include<bits/stdc++.h>
using namespace std;
void ans(int arr[],int n){
    int a=INT_MAX;
    int b=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<=a)b=a,a=arr[i];
        else if(arr[i]<b)b=arr[i];
    }
    cout<<a<<" "<<b<<endl;
}
int main()
{
    freopen("input25.txt","r",stdin);
    freopen("output25.txt","w",stdout);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
	ans(arr, n);
	return 0;
}
