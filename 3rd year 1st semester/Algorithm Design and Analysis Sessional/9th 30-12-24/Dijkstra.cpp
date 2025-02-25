#include <bits/stdc++.h>

using namespace std;

void Dijkstra(const vector<vector<int>>& matrix, int start)
{
    int V = matrix.size();
    vector<int> distance(V, INT_MAX); // Initialize distances to infinity
    vector<bool> inMst(V, false); // Keep track of processed vertices
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap

    // Initialize source
    distance[start] = 0;
    pq.push({0, start}); // Distance to itself is 0

    while (!pq.empty())
    {
        int u = pq.top().second; // Extract the vertex with the smallest distance
        pq.pop();

        if (inMst[u]) continue; // Skip if already processed
        inMst[u] = true;

        // Check all adjacent vertices
        for (int v = 0; v < V; ++v)
        {
            if (matrix[u][v] != INT_MAX)   // If there is an edge
            {
                int weight = matrix[u][v];
                // Relaxation step
                if (distance[u] + weight < distance[v])
                {
                    distance[v] = distance[u] + weight;
                    pq.push({distance[v], v}); // Update priority queue
                }
            }
        }
    }

    // Print the shortest distances from source
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; ++i)
    {
        if (distance[i] == INT_MAX)
        {
            cout << i << "\tINF\n"; // No path exists
        }
        else
        {
            cout << i << "\t" << distance[i] << "\n";
        }
    }
}

// Main function
int main()
{
    vector<vector<int>> matrix =
    {
        {INT_MAX, 10, INT_MAX, 5, INT_MAX},
        {INT_MAX, INT_MAX, 1, 2, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 4},
        {INT_MAX, 3, 9, INT_MAX, 2},
        {7, INT_MAX, 6, INT_MAX, INT_MAX},
    };

    int source = 0; // Source vertex
    Dijkstra(matrix, source);

    return 0;
}
