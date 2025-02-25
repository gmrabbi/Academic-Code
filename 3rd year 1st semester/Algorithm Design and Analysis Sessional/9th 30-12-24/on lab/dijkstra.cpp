#include <bits/stdc++.h>

using namespace std;

void Dijkstra(const vector<vector<int>>& graph, int start=0)
{
    int V = graph.size();
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHEAP;

    key[start] = 0;
    minHEAP.push({0, start});

    while(!minHEAP.empty())
    {
        int u = minHEAP.top().second;
        minHEAP.pop();

        if(inMST[u]) continue;

        inMST[u] = true;

        for(int v =0; v<V; v++)
        {
            if(graph[u][v] != INT_MAX)
            {
                int weight = graph[u][v];
                if(weight+key[u]<key[v])
                {
                    key[v] = key[u]+weight;
                    minHEAP.push({graph[u][v], v});
                }
            }
        }
    }

    for(int i=0; i<V; i++)
    {
        if(key[i] == INT_MAX)
            cout<<i<<"  Infinity."<<endl;
        else
            cout<<i<<"\t"<<key[i]<<endl;
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
