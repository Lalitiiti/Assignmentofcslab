#include<bits/stdc++.h>
using namespace std;
void tarjanDFS(int node, vector<vector<int>>& graph, vector<int>& ids, vector<int>& low, stack<int>& s, vector<bool>& onStack, vector<vector<int>>& sccs, int& id, int& sccCount) {
    ids[node] = low[node] = ++id;
    s.push(node);
    onStack[node] = true;

    for (int neighbor : graph[node]) {
        if (ids[neighbor] == 0) {
            tarjanDFS(neighbor, graph, ids, low, s, onStack, sccs, id, sccCount);
            low[node] = min(low[node], low[neighbor]);
        } else if (onStack[neighbor]) {
            low[node] = min(low[node], ids[neighbor]);
        }
    }

    if (ids[node] == low[node]) {
        sccCount++;
        vector<int> scc;
        int current;
        do {
            current = s.top();
            s.pop();
            onStack[current] = false;
            scc.push_back(current);
        } while (current != node);
        sccs.push_back(scc);
    }
}

vector<vector<int>> findSCCs(int n, vector<vector<int>>& graph) {
    vector<int> ids(n + 1, 0);
    vector<int> low(n + 1, 0);
    stack<int> s;
    vector<bool> onStack(n + 1, false);
    vector<vector<int>> sccs;
    int id = 0;
    int sccCount = 0;

    for (int i = 1; i <= n; ++i) {
        if (ids[i] == 0) {
            tarjanDFS(i, graph, ids, low, s, onStack, sccs, id, sccCount);
        }
    }

    return sccs;
}

int main() {
    freopen("input53.txt","r",stdin);
    freopen("output53.txt","w",stdout);
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V + 1);
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    vector<vector<int>> sccs = findSCCs(V, graph);
    cout << "Strongly Connected Components are:\n";
    for (const auto& scc : sccs) {
        for (int node : scc) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
