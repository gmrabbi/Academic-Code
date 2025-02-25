#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAX = 100;  // Assuming maximum number of tasks is 100

// Perform DFS to find the topological order
void topologicalSortUtil(int u, vector<vector<int>>& G, vector<bool>& visited, stack<int>& resultStack, int n) {
    visited[u] = true;

    // Check all adjacent vertices (tasks that depend on the current task)
    for (int v = 0; v < n; ++v) {
        if (G[u][v] == 1 && !visited[v]) {
            topologicalSortUtil(v, G, visited, resultStack, n);
        }
    }

    // Push the vertex to the stack after processing all its neighbors
    resultStack.push(u);
}

// Topological Sort Function
vector<int> topologicalSort(vector<vector<int>>& G, int n) {
    vector<bool> visited(n, false);
    stack<int> resultStack;

    // Perform DFS for all unvisited nodes
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            topologicalSortUtil(i, G, visited, resultStack, n);
        }
    }

    // Retrieve the topological order from the stack
    vector<int> result;
    while (!resultStack.empty()) {
        result.push_back(resultStack.top());
        resultStack.pop();
    }

    return result;
}

int main() {
    // Example task dependencies represented as a 2D adjacency matrix
    // Task 0 must be completed before 1 and 2
    // Task 1 before 3
    // Task 2 before 3

    int n = 4;  // Number of tasks
    vector<vector<int>> G(n, vector<int>(n, 0));

    // Task 0 -> Task 1, Task 2
    // Task 1 -> Task 3
    // Task 2 -> Task 3
    G[0][1] = 1; // Task 0 -> Task 1
    G[0][2] = 1; // Task 0 -> Task 2
    G[1][3] = 1; // Task 1 -> Task 3
    G[2][3] = 1; // Task 2 -> Task 3

    // Perform Topological Sort
    vector<int> order = topologicalSort(G, n);

    // Output the valid order of tasks
    cout << "A valid order of tasks is:" << endl;
    for (int task : order) {
        cout << task << " ";
    }
    cout << endl;

    return 0;
}
