#include<bits/stdc++.h>
using namespace std;
void DFS(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& order) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, graph, visited, order);
        }
    }
    order.push(node);
}
vector<int> TopologicalSort(vector<vector<int>>& graph, int N) {
    vector<bool> visited(N + 1, false);
    stack<int> order;
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            DFS(i, graph, visited, order);
        }
    }
    vector<int> sorted;
    while (!order.empty()) {
        sorted.push_back(order.top());
        order.pop();
    }
    return sorted;
}
int LongestPath(vector<vector<int>>& graph, int N) {
    vector<int> dp(N + 1, 0);
    vector<int> sorted = TopologicalSort(graph, N);
    int longestPath = 0;
    for (int vertex : sorted) {
        for (int neighbor : graph[vertex]) {
            dp[neighbor] = max(dp[neighbor], dp[vertex] + 1);
            longestPath = max(longestPath, dp[neighbor]);
        }
    }
    return longestPath;
}
int main() {
    freopen("input52.txt","r",stdin);
    freopen("output52.txt","w",stdout);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    int longestPath = LongestPath(graph, N);
    cout << "Length of the longest path: " << longestPath << endl;

    return 0;
}
