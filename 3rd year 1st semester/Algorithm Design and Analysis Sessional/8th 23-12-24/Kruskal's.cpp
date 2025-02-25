#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Comparator to sort edges by weight
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Find operation in Union-Find
int find(vector<int> &parent, int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]); // Path compression
    }
    return parent[i];
}

// Union operation in Union-Find
void unionSets(vector<int> &parent, vector<int> &rank, int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot;
    } else if (rank[xroot] > rank[yroot]) {
        parent[yroot] = xroot;
    } else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int kruskalMST(int V, vector<vector<int>> &matrix) {
    vector<Edge> edges;

    // Convert adjacency matrix to edge list
    for (int i = 0; i < V; ++i) {
        for (int j = i + 1; j < V; ++j) { // Avoid duplicate edges
            if (matrix[i][j] > 0) {
                edges.push_back({i, j, matrix[i][j]});
            }
        }
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; ++i) {
        parent[i] = i;
    }

    int totalWeight = 0;
    vector<Edge> mst; // Store the edges in MST

    for (Edge &edge : edges) {
        int x = find(parent, edge.src);
        int y = find(parent, edge.dest);

        // If including this edge doesn't form a cycle
        if (x != y) {
            mst.push_back(edge);
            totalWeight += edge.weight;
            unionSets(parent, rank, x, y);
        }
    }

    // Print the MST edges and their weights
    cout << "Edge\tWeight\n";
    for (Edge &edge : mst) {
        cout << edge.src << " - " << edge.dest << "\t" << edge.weight << "\n";
    }

    return totalWeight;
}

int main() {
    // Example adjacency matrix
    vector<vector<int>> matrix = {
        {0,4,0,0, 0,0,0,8,0},
        {4,0,8,0, 0,0,0,11,0},
        {0,8,0,7, 0,4,0,0,2},
        {0,0,7,0, 9,14,0,0,0},
        {0,0,0,9, 0,10,0,0,0},

        {0,0,4,14, 10,0,2,0,0},
        {0,0,0,0, 0,2,0,1,6},
        {8,11,0,0, 0,0,1,0,7},
        {0,0,2,0, 0,0,6,7,0},
    };

    int V = matrix.size(); // Number of vertices
    int minWeight = kruskalMST(V, matrix);
    cout << "Minimum weight of the MST: " << minWeight << endl;

    return 0;
}
