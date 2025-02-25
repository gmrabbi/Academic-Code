#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void BellmanFord(const vector<vector<int>>& matrix, int source) {
    int V = matrix.size();
    vector<int> distance(V, numeric_limits<int>::max()); // Initialize distances to infinity
    distance[source] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 0; i < V - 1; ++i) {
        for (int u = 0; u < V; ++u) {
            for (int v = 0; v < V; ++v) {
                if (matrix[u][v] != 0 && distance[u] != numeric_limits<int>::max() && distance[u] + matrix[u][v] < distance[v]) {
                    distance[v] = distance[u] + matrix[u][v];
                }
            }
        }
    }

    // Check for negative weight cycles
    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
            if (matrix[u][v] != 0 && distance[u] != numeric_limits<int>::max() && distance[u] + matrix[u][v] < distance[v]) {
                cout << "Graph contains a negative weight cycle.\n";
                return;
            }
        }
    }

    // Print the shortest distances from source
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; ++i) {
        if (distance[i] == numeric_limits<int>::max()) {
            cout << i << "\tINF\n";
        } else {
            cout << i << "\t" << distance[i] << "\n";
        }
    }
}

// Main function
int main() {
    vector<vector<int>> matrix = {
        {0, 3, 8, 0, -4},
        {0, 0, 0, 1, 7},
        {0, 4, 0, 0, 0},
        {2, 0, -5, 0, 0},
        {0, 0, 0, 6, 0}
    };

    int source = 0; // Source vertex
    BellmanFord(matrix, source);

    return 0;
}
