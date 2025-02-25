#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int primMST(vector<vector<int>> &matrix) {
    int V = matrix.size(); // Number of vertices
    vector<int> key(V, INT_MAX);   // Minimum weight to connect to MST
    vector<int> parent(V, -1);    // To store the MST structure
    vector<bool> inMST(V, false); // To track vertices in MST
    int totalWeight = 0;          // Total weight of the MST

    key[0] = 0; // Start from vertex 0

    for (int count = 0; count < V - 1; ++count) {
        // Find the minimum key value among the vertices not yet in MST
        int minKey = INT_MAX, u = -1;

        for (int v = 0; v < V; ++v) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        // Include the vertex with the smallest key in MST
        inMST[u] = true;
        totalWeight += key[u]; // Add its key (weight) to the total weight

        // Update the keys of adjacent vertices
        for (int v = 0; v < V; ++v) {
            if (matrix[u][v] && !inMST[v] && matrix[u][v] < key[v]) {
                key[v] = matrix[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the MST edges and weights (optional)
    cout << "Edge\tWeight\n";
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << "\t" << matrix[i][parent[i]] << "\n";
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

    int minWeight = primMST(matrix);
    cout << "Minimum weight of the MST: " << minWeight << endl;

    return 0;
}
