#include <bits/stdc++.h>

using namespace std;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

vector<int> color;
vector<int> DiscoveryTime;
vector<int> FinishTime;
vector<int> Ancestor;

int TimeCount;

void DFS_VISIT(vector<vector<int>>& G, int u)
{
    DiscoveryTime[u] = ++TimeCount;
    color[u] = GRAY;

    for(int v=0; v<G[u].size(); v++)
    {
        if(G[u][v] == 1 && color[v] == WHITE)
        {
            Ancestor[v] = u;
            DFS_VISIT(G, v);
        }
    }

    FinishTime[u] = ++TimeCount;
    color[u] = BLACK;
}

void DFS(vector<vector<int>>& G)
{
    int n = G.size();

    color.assign(n, WHITE);
    DiscoveryTime.assign(n, 0);
    FinishTime.assign(n, 0);
    Ancestor.assign(n, -1);

    TimeCount = 0;

    for(int u=0; u<n; u++)
    {
        if(color[u] == WHITE)
            DFS_VISIT(G, u);
    }

    cout<<"vertex\tDiscoveryTime\tFinishTime\tAncestor"<<endl;
    for(int u=0; u<n; u++)
        cout<<u<<"\t"<<DiscoveryTime[u]<<"\t\t"<<FinishTime[u]<<"\t\t"<<Ancestor[u]+1<<endl;
}

int main()
{
    vector<vector<int>> G={

        {0,1,0,0, 0,0,0,0},
        {0,0,0,1, 0,0,0,0},
        {0,0,0,1, 0,0,0,0},
        {0,0,1,0, 0,1,0,0},

        {0,0,0,1, 0,0,0,1},
        {0,0,0,0, 1,0,1,0},
        {0,0,0,0, 0,0,0,1},
        {0,0,0,0, 0,0,1,0}

        /*
        {0,1,0,0, 0,0,0,0},
        {0,0,1,0, 0,0,0,0},
        {0,0,0,1, 1,0,0,0},
        {1,0,0,0, 0,0,0,0},

        {0,0,0,0, 0,1,0,0},
        {0,0,0,0, 0,0,1,0},
        {0,0,0,0, 1,0,0,1},
        {0,0,0,0, 0,0,0,0},
        */
    };

    DFS(G);
    return 0;
}
