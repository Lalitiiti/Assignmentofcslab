#include<bits/stdc++.h>
using namespace std;
vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>ind(V);
	    stack<int>q;
	    vector<int>ans;
	    for(int i=0;i<V;i++){
	        for(auto &it:adj[i])ind[it]++;
	    }
	    for(int i=0;i<V;i++)if(ind[i]==0)q.push(i);
	    while(!q.empty()){
	        int p=q.top();
	        ans.push_back(p);
	        q.pop();
	        for(auto &it:adj[p]){
	            ind[it]--;
	            if(!ind[it])q.push(it);}
	    }
	    return ans;
	    
	}
int main(){
    freopen("input51.txt","r",stdin);
    freopen("output51.txt","w",stdout);
    int V;
    cin>>V;
    vector<int>adj[V];
    int E;
    cin>>E;
    int a,b;
    for(int i=0;i<E;i++)cin>>a>>b,adj[a].push_back(b);
    vector<int>p=topoSort(V,adj);
    for(int i=0;i<V;i++)cout<<p[i]<<" ";
    cout<<endl;
 }   
