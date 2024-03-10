#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> id, low;
vector<bool> visited;
vector<pair<int, int>> bridges;
int ti=0;
void DFS(int u, int parent) {
    id[u] = low[u] = ++ti;
    visited[u] = true;
    int children = 0;
    for (int v : graph[u]) {
        if (!visited[v]) {
            children++;
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= id[u] && parent != -1) {
                cout << "Articulation Point: " << u << endl;
            }
            if (low[v] > id[u]) {
                bridges.push_back({u, v});
            }
        } else if (v != parent) {
            low[u] = min(low[u], id[v]);
        }
    }

    if (parent == -1 && children > 1) {
        cout << "Articulation Point: " << u << endl;
    }
}
void findArticulationPointsAndBridges(int N) {
    id.resize(N + 1);
    low.resize(N + 1);
    visited.resize(N + 1, false);

    for (int u = 1; u <= N; ++u) {
        if (!visited[u]) {
            DFS(u, -1);
        }
    }
}
int main() {
    freopen("input55.txt","r",stdin);
    freopen("output55.txt","w",stdout);
    int N, M;
    cin >> N >> M;
    graph.resize(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // For undirected graph
    }
    findArticulationPointsAndBridges(N);
    cout << "Bridges:\n";
    for (auto bridge : bridges) {
        cout << bridge.first << " - " << bridge.second << endl;
    }

    return 0;
}
