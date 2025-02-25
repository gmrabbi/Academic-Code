// diskstra algorithm
#include <bits/stdc++.h>
using namespace std;

void ShortestPaths(int v, vector<vector<int>>& cost, vector<int>& dist, int n) {
    vector<bool> s(n, false);
    dist.assign(n, INT_MAX);
    dist[v] = 0;

    for (int num = 0; num < n - 1; num++) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!s[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }
        if (u == -1) break;
        s[u] = true;

        for (int w = 0; w < n; w++) {
            if(!s[w] && cost[u][w] != INT_MAX && dist[u] + cost[u][w] < dist[w]){
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
}

int main() {
    vector<vector<int>> cost = {
        {INT_MAX, 1, 3, INT_MAX, INT_MAX, 10, INT_MAX},
        {1, INT_MAX, 1, 7, 5, INT_MAX, 2},
        {3, 1, INT_MAX, 9, 3, INT_MAX, INT_MAX},
        {INT_MAX, 7, 9, INT_MAX, 2, 1, 12},
        {INT_MAX, 5, 3, 2, INT_MAX, 2, INT_MAX},
        {10, INT_MAX, INT_MAX, 1, 2, INT_MAX, INT_MAX},
        {INT_MAX, 2, INT_MAX, 12, INT_MAX, INT_MAX, INT_MAX}
    };

    int n = cost.size();
    vector<int> dist;

    ShortestPaths(0, cost, dist, n);

    cout << "Shortest distances from node 0:" << endl;
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            cout<<"Node 0 to Node "<<i<<": Unreachable"<<endl;
        } else {
            cout<<"Node 0 to Node "<<i<<": "<< dist[i]<<endl;
        }
    }

    return 0;
}
