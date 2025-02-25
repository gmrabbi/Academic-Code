#include <bits/stdc++.h>

using namespace std;

void prim(vector<vector<int>>& graph, int start=0)
{
    int V = graph.size();
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMst(V, false);
    vector<pair<int,int>> mstEdges;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    int totalWeigt = 0;

    key[start] = 0;
    minHeap.push({0, start});

    while(!minHeap.empty())
    {
        int u = minHeap.top().second;
        int weight = minHeap.top().first;
        minHeap.pop();

        if(inMst[u]) continue;

        inMst[u] = true;
        totalWeigt += weight;

        if(parent[u] != -1)
            mstEdges.push_back({parent[u], u});

        for(int v=0; v<V; v++)
        {
            if(!inMst[v] && graph[u][v]!=0&&graph[u][v]<key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
                minHeap.push({graph[u][v], v});
            }
        }
    }

    cout<<"Edges    Weight"<<endl;
    for(auto edge: mstEdges)
    {
        cout<<edge.first<<" - "<<edge.second<<"     "<<graph[edge.first][edge.second]<<endl;
    }
    cout<<"Total weight:"<<totalWeigt<<endl;

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
    prim(graph);
    auto End = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = End - Start;
    cout<<duration.count()<<" mS"<<endl;
    return 0;
}



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
