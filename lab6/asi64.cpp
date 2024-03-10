#include<bits/stdc++.h>
using namespace std;
bool k=0;
bool hasCycle(vector<vector<int>>graph,int p,vector<bool> &vi){
    vi[p]=true;
    for(auto &it:graph[p]){
        if(vi[it]){
            k=1;
            return true;}
        hasCycle(graph,it,vi);
    }
    return false;
}
int main() {
    freopen("input54.txt","r",stdin);
    freopen("output54.txt","w",stdout);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1);
    vector<bool> vi(N + 1, false);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
for(int i=1;i<=N;i++)if(!vi[i])hasCycle(graph,i,vi);
    if (k) {
        cout << "Graph contains a cycle.\n";
    } else {
        cout << "Graph does not contain a cycle.\n";
    }

    return 0;
}
