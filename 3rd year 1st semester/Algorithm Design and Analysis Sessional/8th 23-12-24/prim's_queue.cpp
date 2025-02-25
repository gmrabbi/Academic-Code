#include <bits/stdc++.h>

using namespace std;

// Function to implement Prim's Algorithm
void prim(const vector<vector<int>>& graph, int start = 0) {
    int V = graph.size();  // Number of vertices

    // To track the minimum edge weight for each vertex
    vector<int> key(V, INT_MAX);

    // To track which vertices are included in the MST
    vector<bool> inMST(V, false);

    // Priority queue to select the edge with the minimum weight (min-heap)
    // pair<int, int> -> (weight, vertex)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    // Start from the given vertex
    key[start] = 0;
    minHeap.push({0, start});  // Push the starting vertex with weight 0

    int totalWeight = 0;  // To store the total weight of the MST
    vector<pair<int, int>> mstEdges;  // To store the MST edges (vertex, weight)
    vector<int> parent(V, -1); // To track the parent of each vertex

    while (!minHeap.empty()) {
        // Extract the vertex with the minimum weight edge
        int u = minHeap.top().second;  // Get vertex
        int weight = minHeap.top().first;  // Get weight
        minHeap.pop();

        // Skip if the vertex is already included in MST
        if (inMST[u]) continue;

        // Include vertex in MST
        inMST[u] = true;
        totalWeight += weight;

        // Store the edge in MST if it’s not the starting node
        if (parent[u] != -1) {
            mstEdges.push_back({parent[u], u});
        }

        // Explore the neighbors of the current vertex
        for (int v = 0; v < V; ++v) {
            if (!inMST[v] && graph[u][v] != 0 && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
                minHeap.push({graph[u][v], v});
            }
        }
    }

    // Output the MST edges and their weights
    cout << "Edge    Weight\n";
    for (auto edge : mstEdges) {
        cout << edge.first << " - " << edge.second << "   " << graph[edge.first][edge.second] << endl;
    }
    cout << "Minimum weight of the MST: " << totalWeight << endl;
}

int main() {
    // Example graph (adjacency matrix)
    vector<vector<int>> graph = {
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

    // Call the function starting from vertex 0
    prim(graph);

    return 0;
}
