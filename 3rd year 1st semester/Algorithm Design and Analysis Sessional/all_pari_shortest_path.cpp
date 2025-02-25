#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Function to calculate the total cost of a given path
int calculateCost(vector<vector<int>>& graph, vector<int>& path) {
    int totalCost = 0;
    for (size_t i = 0; i < path.size() - 1; ++i) {
        totalCost += graph[path[i]][path[i + 1]];
    }
    totalCost += graph[path.back()][path[0]]; // Return to the starting city
    return totalCost;
}

// Function to find the shortest path using brute force
pair<int, vector<int>> travelingSalesmanProblem(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> cities(n);
    for (int i = 0; i < n; ++i) {
        cities[i] = i;
    }

    int minCost = INT_MAX;
    vector<int> bestPath;

    // Generate all permutations of cities to find the shortest path
    do {
        int currentCost = calculateCost(graph, cities);
        if (currentCost < minCost) {
            minCost = currentCost;
            bestPath = cities;
        }
    } while (next_permutation(cities.begin() + 1, cities.end()));

    return {minCost, bestPath};
}

int main() {
    // Adjacency matrix representation of the graph
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {5, 0, 9, 10},
        {6, 13, 0, 12},
        {8, 8, 9, 0}

        /*
        {INT_MAX, 20, 30, 10, 11},
        {15, INT_MAX, 16, 4, 2},
        {3, 5, INT_MAX, 2, 4},
        {19, 6, 18, INT_MAX, 3},
        {16, 4, 7, 16, INT_MAX}
        */
    };

    auto result = travelingSalesmanProblem(graph);
    int minCost = result.first;
    vector<int> bestPath = result.second;

    cout << "The minimum cost to visit all cities is: " << minCost << endl;
    cout << "The path is: ";
    for (int city : bestPath) {
        cout << city+1 << " -> ";
    }
    cout << bestPath[0]+1 << endl; // Return to the starting city

    cout << "Cost details for each segment:\n";
    for (size_t i = 0; i < bestPath.size() - 1; ++i) {
        cout << bestPath[i]+1 << " to " << bestPath[i + 1]+1 << " : " << graph[bestPath[i]][bestPath[i + 1]] << endl;
    }
    cout << bestPath.back() << " to " << bestPath[0]+1 << " : " << graph[bestPath.back()][bestPath[0]] << endl;

    return 0;
}
