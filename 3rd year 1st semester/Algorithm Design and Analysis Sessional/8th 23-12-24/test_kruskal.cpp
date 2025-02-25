#include <bits/stdc++.h>

using namespace std;

struct Edge
{  int u, v, weight;  };

void makeSet(int V, vector<int>& parent, vector<int>& rank)
{
    for(int i=0; i<V; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
int findSet(int node, vector<int>& parent)
{
    if(parent[node] != node)
        parent[node] = findSet(parent[node], parent);
    return parent[node];
}
void UnionSet(int u, int v, vector<int>& parent, vector<int>& rank)
{
    int rootU = findSet(u, parent);
    int rootV = findSet(v, parent);

    if(rootU != rootV)
    {
        if(rank[rootU]>=rank[rootV])
            parent[rootV] = rootU;
        else if(rank[rootU]<rank[rootV])
            parent[rootU] = rootV;
        else
            rank[rootU]++;
    }
}
void kruskal(int V, vector<vector<int>>& adjMatrix)
{
    vector<int> parent(V);
    vector<int> rank(V);
    vector<Edge> edges;
    vector<Edge> mstEdges;
    int totalWeight = 0;

    for(int i=0; i<V; i++)
    {
        for(int j=i+1; j<V; j++)
        {
            if(adjMatrix[i][j] != 0)
                edges.push_back({i, j, adjMatrix[i][j]});
        }
    }
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b)
         {return a.weight<b.weight;});
    makeSet(V, parent, rank);

    for(Edge edge: edges)
    {
        int u = edge.u;
        int v = edge.v;
        if(findSet(u, parent) != findSet(v, parent) )
        {
            UnionSet(u, v, parent, rank);
            mstEdges.push_back(edge);
            totalWeight += edge.weight;
        }
    }

    cout<<"Edge     Wegiht"<<endl;
    for(Edge edge: mstEdges)
    {
        cout<<edge.u<<" - "<<edge.v<<"      "<<edge.weight<<endl;
    }
    cout<<totalWeight<<endl;

}

int main()
{
    vector<vector<int>> graph = {
    // provided sparse graph
    {0, 1, 2,  0, 0, 0},
    {1, 0, 3,  0, 0, 0},
    {2, 3, 0,  4, 5, 6},

    {0, 0, 4,  0, 7, 0},
    {0, 0, 5,  7, 0, 8},
    {0, 0, 6,  0, 8, 0},
    };

    auto Start = chrono::high_resolution_clock::now();
    kruskal(graph.size(), graph);
    auto End = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = End - Start;

    cout<<duration.count()<<" ms"<<endl;

    return 0;
}

/*
provided sparse graph
    {0, 1, 2,  0, 0, 0},
    {1, 0, 3,  0, 0, 0},
    {2, 3, 0,  4, 5, 6},

    {0, 0, 4,  0, 7, 0},
    {0, 0, 5,  7, 0, 8},
    {0, 0, 6,  0, 8, 0},


*/

/*

// provided dense graph
    {0,3,0, 4,4,0,0, 0,0,0},
    {3,0,10, 0,2,3,0, 0,0,0},
    {0,10,0, 0,0,6,1, 0,0,0},

    {4,0,0, 0,5,0,0, 6,0,0},
    {4,2,0, 5,0,11,0, 2,1,0},
    {0,3,6, 0,11,0,2, 0,3,11},
    {0,0,1, 0,0,2,0, 0,0,8},

    {0,0,0, 6,2,0,0, 0,4,0},
    {0,0,0, 0,1,3,0, 4,0,7},
    {0,0,0, 0,0,11,8, 0,7,0},
    */








/*

        {0,4,0,0, 0,0,0,8,0},
        {4,0,8,0, 0,0,0,11,0},
        {0,8,0,7, 0,4,0,0,2},
        {0,0,7,0, 9,14,0,0,0},
        {0,0,0,9, 0,10,0,0,0},

        {0,0,4,14, 10,0,2,0,0},
        {0,0,0,0, 0,2,0,1,6},
        {8,11,0,0, 0,0,1,0,7},
        {0,0,2,0, 0,0,6,7,0},

*/
