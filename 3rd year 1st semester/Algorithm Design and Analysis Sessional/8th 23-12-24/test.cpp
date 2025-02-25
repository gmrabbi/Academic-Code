#include <bits/stdc++.h>

using namespace std;

struct Edge
{ int u, v, weight; };

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

void unionSet(int u, int v, vector<int>& parent, vector<int>& rank)
{
    int rootu = findSet(u, parent);
    int rootv = findSet(v, parent);

    if(rootu != rootv)
    {
        if(rank[rootu]<= rank[rootv])
            parent[rootv] = rootu;
        else if(rank[rootu]> rank[rootv])
            parent[rootv] = rootu;
        else
            rank[rootu]++;
    }
}

void Kruskal(int V, vector<vector<int>>& graph)
{
    vector<int> rank(V);
    vector<int> parent(V);
    vector<Edge> edges;
    vector<Edge> MstEdges;
    int total_weight = 0;

    for(int i=0; i<V; i++)
    {
        for(int j=i+1; j<V; j++)
        {
            if(graph[i][j] != 0)
                edges.push_back({i,j,graph[i][j]});
        }
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){return a.weight<b.weight;});
    makeSet(V, parent, rank);


    for(Edge edge: edges)
    {
        int u = edge.u;
        int v = edge.v;
        if(findSet(u,parent) != findSet(v,parent))
        {
            unionSet(u,v,parent, rank);
            MstEdges.push_back(edge);
            total_weight += edge.weight;
        }
    }

    for(auto edge: MstEdges)
        cout<<edge.u<<" - "<<edge.v<<"   "<<edge.weight<<endl;
    cout<<"Total weight:"<<total_weight<<endl;

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
    Kruskal(graph.size(), graph);
    auto End = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = End - Start;

    cout<<duration.count()<<" ms"<<endl;

    return 0;
}
