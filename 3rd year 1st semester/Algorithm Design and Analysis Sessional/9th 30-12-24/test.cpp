#include <bits/stdc++.h>

using namespace std;

void dijktra(const vector<vector<int>>& graph, int start)
{
    int V = graph.size();
    vector<int> distance(V, INT_MAX);
    vector<bool> inMst(V, false);
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> minHeap;

    distance[start] = 0;
    minHeap.push({0,start});

    while(!minHeap.empty())
    {
        int u = minHeap.top().second;
        minHeap.pop();

        if(inMst[u]) continue;
        inMst[u] = true;

        for(int v=0; v<V; v++)
        {
            if(graph[u][v]!=INT_MAX)
            {
                int weight = graph[u][v];
                if(weight+distance[u]<distance[v])
                {
                    distance[v] = weight+distance[u];
                    minHeap.push({distance[v],v});
                }
            }
        }
    }
    cout<<"vertex\tsource to distance"<<endl;
    for(int v=0; v<V; v++)
    {
        if(distance[v] == INT_MAX)
            cout<<v<<"\tInfinity"<<endl;
        else
            cout<<v<<"\t"<<distance[v]<<endl;
    }

}

int LCS(int i, int j, const string& a, const string& b)
{
    if(i==a.length() || j==b.length())
        return 0;
    if(a[i]==b[j])
        return 1+(LCS(i+1, j+1, a, b));
    else
        return max(LCS(i+1, j, a, b), LCS(i, j+1, a, b));
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

    dijktra(graph, 0);


    string a = "AGGTAB";
    string b = "GXTXAYB";

    int result = LCS(0,0,a, b);
    cout<<result<<endl;

    return 0;
}
