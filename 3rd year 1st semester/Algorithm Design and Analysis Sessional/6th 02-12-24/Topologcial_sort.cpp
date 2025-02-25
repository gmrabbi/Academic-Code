#include <bits/stdc++.h>

using namespace std;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

vector<int> color;
vector<int> DescoveryTime;
vector<int> FinishTime;
vector<int> Ancestor;
vector<int> finishvectex;
int timeCount;

void DFS_VISIT(vector<vector<int>>& G, int u)
{
    timeCount++;
    DescoveryTime[u] = timeCount;
    color[u] = GRAY;

    for(int v=0; v<G[u].size(); v++)
    {
        if(G[u][v]==1 && color[v]==WHITE)
        {
            Ancestor[v] = u;
            DFS_VISIT(G, v);
        }
    }
    timeCount++;
    FinishTime[u] = timeCount;
    color[u] = BLACK;
    finishvectex.push_back(u);
}

void DFS(vector<vector<int>>& G)
{   int n = G.size();
    color.assign(n, WHITE);
    DescoveryTime.assign(n, 0);
    FinishTime.assign(n, 0);
    Ancestor.assign(n, -1);
    finishvectex.clear();

    for(int u=0; u<n; u++)
    {
        if(color[u] == WHITE)
            DFS_VISIT(G, u);
    }
}
vector<int> Topological_sort(vector<vector<int>>& G)
{
    DFS(G);
    reverse(finishvectex.begin(), finishvectex.end());
    return finishvectex;
}
int main()
{
    vector<vector<int>> G=
    {
        {0,1,0,0, 0,0,0,0},
        {0,0,1,0, 0,0,0,0},
        {0,0,0,1, 1,0,0,0},
        {1,0,0,0, 0,0,0,0},

        {0,0,0,0, 0,1,0,0},
        {0,0,0,0, 0,0,1,0},
        {0,0,0,0, 1,0,0,1},
        {0,0,0,0, 0,0,0,0},
    };
    vector<int> SortedOrder = Topological_sort(G);
    for(int i: SortedOrder)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}

/*
        {0,0,1,0, 0,0,0,0},
        {0,0,1,0, 0,0,0,0},
        {0,0,0,1, 1,0,0,0},
        {0,0,0,0, 0,1,0,0},

        {0,0,0,0, 0,1,0,0},
        {0,0,0,0, 0,0,1,1},
        {0,0,0,0, 0,0,0,0},
        {0,0,0,0, 0,0,0,0},
*/
        /*
        {0,1,1,0, 0,0,0},
        {0,0,1,0, 0,1,0},
        {0,0,0,1, 0,0,0},
        {0,0,0,0, 0,0,0},
        {0,0,0,0, 0,0,0},
        {0,0,0,1, 1,0,0},
        {0,1,0,0, 0,1,0}
        */


        /*

        {0,1,1,0,1,0,0,0},
        {0,0,0,0,0,1,0,0},
        {0,0,0,1,0,1,1,0},
        {0,0,0,0,1,0,0,1},
        {0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1},
        {0,0,0,0,1,0,0,1},
        {0,0,0,0,0,0,0,0}
        */
