#include <bits/stdc++.h>
using namespace std;
// implementation of traveling Salesman Problem
int travllingSalesmanProblem(int v,vector<vector<int>>&graph,int s)
{
    // store all vertex apart from source vertex
    vector<int> vertex;
    for (int i = 0; i < v; i++)
        if (i != s)
            vertex.push_back(i);
 
    // store minimum weight Hamiltonian Cycle.
    int min_path = INT_MAX;
    do {
 
        // store current Path weight(cost)
        int current_pathweight = 0;
 
        // compute current path weight
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
        min_path = min(min_path, current_pathweight);
    } while (
        next_permutation(vertex.begin(), vertex.end()));
 
    return min_path;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> g(n,vector<int>(n,INT_MAX));
    int x;
    cin>>x;
    for(int i=0;i<x;i++){
        int a,b,w;
        cin>>a>>b>>w;
        g[a][b]=w;
        g[b][a]=w;
    }
    int s = 0;
    cout << travllingSalesmanProblem(n,g,s) << endl;
    return 0;
}