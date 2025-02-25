#include <bits/stdc++.h>

using namespace std;

void Dijkstra(const vector<vector<int>>& graph, int start=0)
{
    int n = graph.size();
    vector<int> key(n, INT_MAX);
    vector<bool> inMst(n, false);
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> minHeap;

    key[start] = 0;
    minHeap.push({0, start});

    while(!minHeap.empty())
    {
        int u = minHeap.top().second;
        minHeap.pop();

        if(inMst[u]) continue;
        inMst[u] = false;

        for(int v=0; v<n; v++)
        {
            if(graph[u][v] != INT_MAX)
            {
                int weight = graph[u][v];
                if(weight+key[u]<key[v])
                {
                    key[v] = key[u]+weight;
                    minHeap.push({key[v], v});
                }
            }
        }
    }
    cout<<"vectex\tsource to distance"<<endl;
    for(int v=0; v<n; v++)
    {
        if(key[v]==INT_MAX)
            cout<<v<<"\tInfinity"<<endl;
        else
            cout<<v<<"\t"<<key[v]<<endl;
    }
}

int main()
{
    vector<vector<int>> graph={
    {INT_MAX, 10, INT_MAX, 5, INT_MAX},
    {INT_MAX, INT_MAX, 1, 2, INT_MAX},
    {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 4},
    {INT_MAX, 3, 9, INT_MAX, 2},
    {INT_MAX, INT_MAX, 6, INT_MAX, INT_MAX},
    };

    Dijkstra(graph);

    return 0;
}
