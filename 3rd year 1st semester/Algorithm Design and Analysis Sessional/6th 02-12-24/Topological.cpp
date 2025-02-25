#include <bits/stdc++.h>

using namespace std;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

vector<int> color;
vector<int> DiscoveryTime;
vector<int> FinishTime;
vector<int> Ancestor;
vector<int> TopologicalORder;

int TimeCount;

void DFS_VISIT(vector<vector<int>>& G, int u)
{
    DiscoveryTime[u] = ++TimeCount;
    color[u] = GRAY;

    for(int v=0; v<G[u].size(); v++)
    {
        if(G[u][v]==1 && color[v]==WHITE)
        {
            Ancestor[v] = u;
            DFS_VISIT(G, v);
        }
    }
    FinishTime[u] = ++TimeCount;
    color[u] = BLACK;
    TopologicalORder.push_back(u);
}

void DFS(vector<vector<int>>& G)
{
    int n = G.size();

    color.assign(n, WHITE);
    DiscoveryTime.assign(n, 0);
    FinishTime.assign(n, 0);
    Ancestor.assign(n, -1);
    TopologicalORder.clear();

    TimeCount = 0;

    for(int u=0; u<n; u++)
    {
        if(color[u] == WHITE)
            DFS_VISIT(G, u);
    }
}

vector<int> TOPOLOGICAL_SORT(vector<vector<int>>& G)
{
    DFS(G);
    reverse(TopologicalORder.begin(), TopologicalORder.end());
    return TopologicalORder;
}

int main()
{
    vector<vector<int>> G={
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    vector<int> sortedOrder = TOPOLOGICAL_SORT(G);

    for(auto i: sortedOrder)
        cout<<i+1<<" ";
    cout<<endl;

    return 0;
}

