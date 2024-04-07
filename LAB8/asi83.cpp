#include<bits/stdc++.h>
using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
    Edge() {}
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
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

// Function to find the minimum spanning tree
vector<Edge> findMST(vector<Edge>& edges, int V, int E) {
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

        // If including this edge does not cause cycle, include it
        if (x != y) {
            MST.push_back(nextEdge);
            unionSets(subsets, x, y);
            edgeCount++;
        }
    }

    // Deallocate memory
    delete[] subsets;

    return MST;
}

// Function to find the second best minimum spanning tree
vector<Edge> secondBestMST(vector<Edge>& edges, int V, int E) {
    // Find the initial MST
    vector<Edge> MST = findMST(edges, V, E);

    int secondBestWeight = INT_MAX;
    vector<Edge> secondBestMST;

    // Iterate through each edge in the MST and exclude it
    for (Edge excludedEdge : MST) {
        // Create a copy of edges excluding the current edge
        vector<Edge> remainingEdges;
        for (Edge e : edges) {
            if (!(e.src == excludedEdge.src && e.dest == excludedEdge.dest && e.weight == excludedEdge.weight))
                remainingEdges.push_back(e);
        }

        // Find MST of the remaining graph
        vector<Edge> currentMST = findMST(remainingEdges, V, E - 1);

        // Check if the weight of this MST is better than the current second best MST
        int currentWeight = 0;
        for (Edge e : currentMST)
            currentWeight += e.weight;

        if (currentMST.size()==V-1&&currentWeight < secondBestWeight) {
            secondBestWeight = currentWeight;
            secondBestMST = currentMST;
        }
    }

    return secondBestMST;
}

int main() {
   freopen("input83.txt","r",stdin);
    freopen("output83.txt","w",stdout);
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

    // Find the second best minimum spanning tree
    vector<Edge> secondBest = secondBestMST(edges, V, E);

    // Print the edges of the second best minimum spanning tree
    cout << "Second Best Minimum Spanning Tree Edges:\n";
    for (const auto& edge : secondBest) {
        cout << edge.src << " -- " << edge.dest << " weight: " << edge.weight << endl;
    }

    return 0;
}
