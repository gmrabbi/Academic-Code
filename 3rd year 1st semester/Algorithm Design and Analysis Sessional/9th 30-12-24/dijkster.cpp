#include <bits/stdc++.h>

using namespace std;

void Dijkstra(const vector<vector<int>>& matrix, int start)
{
    int V = matrix.size();
    vector<int> distance(V, INT_MAX);
    vector<bool> inMST(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[start] = 0;
    pq.push({0, start});

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if(inMST[u]) continue;
        inMST[u] = true;

        for(int v=0; v<V; v++)
        {
            if(matrix[u][v] != INT_MAX)
            {
                int weight = matrix[u][v];
                if(distance[u]+weight < distance[v])
                {
                    distance[v] =  distance[u]+weight;
                    pq.push({distance[v], v});
                }
            }
        }
    }

    cout<<"Vertex\tdistance from source"<<endl;
    for(int i=0; i<V; i++)
    {
        if(distance[i] == INT_MAX)
        {
            cout<<i<<"\tInfinity"<<endl;
        }
        else
            cout<<i<<"\t"<<distance[i]<<endl;
    }

}

int main()
{
    vector<vector<int>> matrix={
        {INT_MAX, 10, INT_MAX, 5, INT_MAX},
        {INT_MAX, INT_MAX, 1, 2, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 4},
        {INT_MAX, 3, 9, INT_MAX, 2},
        {7, INT_MAX, 6, INT_MAX, INT_MAX}
    };

    int source = 0;
    Dijkstra(matrix, source);


    return 0;
}

