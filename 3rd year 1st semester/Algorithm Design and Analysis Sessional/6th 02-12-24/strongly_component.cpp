#include <bits/stdc++.h>

using namespace std;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

vector<int> color;
vector<int> DescoveryTime;
vector<int> FinishTime;
vector<int> Ancestor;
stack<int> finishvectex;

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
    finishvectex.push(u);
}

void DFS(vector<vector<int>>& G)
{
    int n = G.size();
    color.assign(n, WHITE);
    DescoveryTime.assign(n, 0);
    FinishTime.assign(n, 0);
    Ancestor.assign(n, -1);

    for(int u=0; u<n; u++)
    {
        if(color[u] == WHITE)
            DFS_VISIT(G, u);
    }
}


vector<vector<int>> Transpose(vector<vector<int>> & G)
{
    int n = G.size();
    vector<vector<int>> GT(n, vector<int>(n, 0));

    for(int u=0; u<n; u++)
    {
        for(int v=0; v<G[u].size(); v++)
        {
            if(G[u][v]==1)
                GT[v][u] = 1;
        }
    }
    return GT;
}

void DFS_VISIT_snd(vector<vector<int>>& G, int u, vector<int>& component)
{
    color[u] = GRAY;
    component.push_back(u);

    for(int v=0; v<G[u].size(); v++)
    {
        if(G[u][v]==1 && color[v]==WHITE)
        {
            DFS_VISIT_snd(G, v, component);
        }
    }
    color[u] = BLACK;
}

void dfs_fsccs(vector<vector<int>>& G)
{
    DFS(G);
    vector<vector<int>> GT = Transpose(G);
    int n = G.size();
    color.assign(n, WHITE);




    while(!finishvectex.empty())
    {
    int u = finishvectex.top();
    finishvectex.pop();
        if (color[u] == WHITE)
        {
            vector<int> component;
            DFS_VISIT_snd(GT, u, component);

            cout<<"{";
            for(auto i: component)
                cout<<i<<" ";
            cout<<"}"<<endl;
        }
    }
}

int main()
{
    vector<vector<int>> G=
    {
        {0,1,0,0, 0,0,0,0},
        {0,0,0,1, 0,0,0,0},
        {0,0,0,1, 0,0,0,0},
        {0,0,1,0, 0,1,0,0},

        {0,0,0,1, 0,0,0,1},
        {0,0,0,0, 1,0,1,0},
        {0,0,0,0, 0,0,0,1},
        {0,0,0,0, 0,0,1,0}
        /*
        {0,1,0,0, 0,0,0,0, 0,0,0},
        {0,0,1,1, 0,1,0,0, 0,0,0},
        {1,0,0,0, 1,0,0,1, 0,0,0},
        {0,0,0,0, 0,0,1,0, 0,0,0},

        {0,0,0,1, 0,0,0,1, 0,0,1},
        {0,1,0,1, 0,0,0,0, 0,0,0},
        {0,0,0,0, 0,0,0,0, 1,0,0},
        {0,0,0,0, 0,0,0,0, 0,0,0},

        {0,0,0,1, 0,0,0,0, 0,0,0},
        {0,0,0,0, 1,0,0,0, 0,0,0},
        {0,0,0,0, 0,0,0,0, 0,1,0},
        */
    };

    dfs_fsccs(G);

    return 0;
}

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

        /*

        {0,1,0,0,0, 0,0,1,0,0},
        {0,1,1,0,0, 0,0,0,0,0},
        {0,1,0,0,0, 1,0,0,0,0},
        {0,0,1,0,1, 0,0,0,0,0},
        {0,0,0,0,0, 0,0,0,0,1},

        {0,0,0,1,0, 0,1,0,0,1},
        {0,0,1,0,0, 0,0,0,0,0},
        {1,0,0,0,0, 0,1,0,1,0},
        {0,0,0,0,0, 0,1,0,0,1},
        {0,0,0,0,1, 0,0,0,0,0},
        */
