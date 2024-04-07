#include<bits/stdc++.h>
using namespace std;
struct Edge {
    int src, dest, weight;
};
struct Subset {
    int parent;
    int rank;
};
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight > b.weight;
}
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void unionSets(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
void maximumSpanningTree(vector<Edge>& edges, int V, int E) {
    sort(edges.begin(), edges.end(), compareEdges);
    Subset* subsets = new Subset[V];
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    int edgeCount = 0;
    int index = 0;
    vector<Edge> MST;
    while (edgeCount < V - 1 && index < E) {
        Edge nextEdge = edges[index++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);
        if (x != y) {
            MST.push_back(nextEdge);
            unionSets(subsets, x, y);
            edgeCount++;
        }
    }
    cout << "Maximum Spanning Tree Edges:\n";
    for (const auto& edge : MST) {
        cout << edge.src << " -- " << edge.dest << " weight: " << edge.weight << endl;
    }
    delete[] subsets;
}

int main() {
    freopen("input81.txt","r",stdin);
    freopen("output81.txt","w",stdout);
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // Input the edges
    vector<Edge> edges(E);
    cout << "Enter edges (source, destination, weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
    maximumSpanningTree(edges, V, E);

    return 0;
}
