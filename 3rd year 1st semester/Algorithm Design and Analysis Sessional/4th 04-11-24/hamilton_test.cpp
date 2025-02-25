#include <bits/stdc++.h>

using namespace std;

vector<int> x;                      // To store the path
vector<vector<int>> G;              // Adjacency matrix of the graph
int n = 0;                           // Number of vertices

void NextValue(int k)
{
    while (true)
    {
        x[k] = (x[k] + 1) % n;       // Correct modulo operation to n
        if (x[k] == 0)
        {
            return; // If no valid vertex is found
        }

        // Check if the current vertex can be added to the path
        if (G[x[k - 1]][x[k]] != 0)
        {
            int j;
            for (j = 0; j < k; j++)   // Check all previous vertices
            {
                if (x[j] == x[k])     // Ensure x[k] is not already in the path
                    break;
            }
            // If x[k] is not already in the path
            if (j == k)
            {
                if((k<n-1) || ( (k==n-1)&& (G[x[n-1]][x[0]] != 0) ) )
                    return; // Valid next vertex found
            }
        }
    }
}

void Hamiltonian(int k)
{
    while (true)
    {
        NextValue(k);
        if (x[k] == 0) // If no valid vertex is found
            return;

        if (k == n - 1)   // If we've filled the path
        {
            // Check if we can return to the starting vertex to form a cycle
            for (int i = 0; i < n; i++)
            {
                cout << x[i]+1 << " "; // Print the path
            }
            cout<< x[0]+1 << endl;
        }
        else
        {
            Hamiltonian(k + 1); // Recur for the next vertex
        }
    }
}

int main()
{
    // How many vertices

    G =
    {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
    n = G.size(); // You can change this number for different graph sizes

    // Initialize x with -1 indicating unvisited
    x.resize(n, 0);
    x[0] = 0; // Start from vertex 0

    Hamiltonian(1); // Start Hamiltonian path search from the first vertex

    return 0;
}
