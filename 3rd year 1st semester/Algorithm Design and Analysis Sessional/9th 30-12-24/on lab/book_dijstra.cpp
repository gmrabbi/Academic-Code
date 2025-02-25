#include <bits/stdc++.h>

using namespace std;

void ShortestPaths(int v, vector<vector<int>>& cost, vector<int>& dist, int n)
{
    vector<int> s;
    for(int i=1; i<=n; i++)
    {
        s[i] = false;
        dist[i] = cost[v][i];
    }
    s[v] = true;
    dist[v] = 0;

    int u = 1;
    for(int num =2; num<n; num++ )
    {
        for(int i=1; i<=n; i++)
        {
            if(!s[num] || dist[u]<dist[num])
                u = i;
        }
        s[u] = true;

        for(int w=1; w<n; w++)
        {
            if(!s[w])
            {
                if(dist[w]>dist[u]+cost[u][w])
                    dist[w] = dist[u]+cost[u][w];
            }
        }
    }
}

int main()
{
    vector<vector<int>> cost={
    {INT_MAX,1,3, INT_MAX,INT_MAX,10,INT_MAX},
    {1,INT_MAX,1, 7,5,INT_MAX,2},
    {3,1,INT_MAX, 9,3,INT_MAX,INT_MAX},
    {INT_MAX,7,9, INT_MAX,2,1,12},

    {INT_MAX,5,3, 2,INT_MAX,2,INT_MAX},
    {10,INT_MAX,INT_MAX, 1,2,INT_MAX,INT_MAX},
    {INT_MAX,2,INT_MAX, 12,INT_MAX,INT_MAX,INT_MAX}
    };

    vector<int> dist(cost.size(), 0);

    ShortestPaths(0,cost, dist, cost.size());


    return 0;
}
