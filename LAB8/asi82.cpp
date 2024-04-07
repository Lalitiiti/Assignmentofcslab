#include<bits/stdc++.h>
using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
    char color; // Color of the edge ('B' for black, 'G' for green)
};

// Structure to represent a subset for Union-Find
struct Subset {
    int parent;
    int rank;
};

// Comparison function to sort edges by weight
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight; // Sort in non-decreasing order of weight
}

// Find operation for Union-Find
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union operation for Union-Find
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

// Function to find the minimum spanning tree with alternating colored edges
void alternatingMST(vector<Edge>& edges, int V, int E) {
    // Sort edges by weight in non-decreasing order
    sort(edges.begin(), edges.end(), compareEdges);

    // Allocate memory for subsets
    Subset* subsets = new Subset[V];
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Initialize variables
    int edgeCount = 0;
    int index = 0;
    vector<Edge> MST;

    // Loop through all edges
    while (edgeCount < V - 1 && index < E) {
        // Pick the smallest edge
        Edge nextEdge = edges[index++];

        // Find root of sets of the vertices of the current edge
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If including this edge does not cause cycle and maintains alternating colors, include it
        if (x != y && (MST.empty() || MST.back().color != nextEdge.color)) {
            MST.push_back(nextEdge);
            unionSets(subsets, x, y);
            edgeCount++;
        }
    }

    // Print the edges of the minimum spanning tree
    cout << "Minimum Spanning Tree Edges with Alternating Colors:\n";
    for (const auto& edge : MST) {
        cout << edge.src << " -- " << edge.dest << " weight: " << edge.weight << " color: " << edge.color << endl;
    }

    // Deallocate memory
    delete[] subsets;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // Input the edges
    vector<Edge> edges(E);
    cout << "Enter edges (source, destination, weight, color (B/G)):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight >> edges[i].color;
    }

    // Find minimum spanning tree with alternating colored edges
    alternatingMST(edges, V, E);

    return 0;
}
