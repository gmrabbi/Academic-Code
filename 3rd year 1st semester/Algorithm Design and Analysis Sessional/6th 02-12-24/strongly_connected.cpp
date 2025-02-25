#include <bits/stdc++.h>

using namespace std;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

vector<int> color;
vector<int> Ancestor;
vector<int> FinishTime;
vector<int> DiscoveryTime;
stack<int> finishStack;
int TimeCount;

void VISIT_DFS(vector<vector<int>>& G, int u)
{
    color[u] = GRAY;
    DiscoveryTime[u] = ++TimeCount;

    for(int v=0; v<G[u].size(); v++)
    {
        if(G[u][v]==1 && color[v] == WHITE)
        {
            Ancestor[v] = u;
            VISIT_DFS(G, v);
        }
    }
    color[u] = BLACK;
    FinishTime[u] = ++TimeCount;
    finishStack.push(u);
}

void DFS(vector<vector<int>>& G)
{
    int n = G.size();
    color.assign(n, WHITE);
    Ancestor.assign(n, -1);
    FinishTime.assign(n, 0);
    DiscoveryTime.assign(n, 0);

    for(int u=0; u<n; u++)
    {
        if(color[u] == WHITE)
            VISIT_DFS(G, u);
    }

    cout<<"Vertex\tDiscoveryTime\tFinishTime\tAncestor"<<endl;
    for(int u=0; u<n; u++)
        cout<<u+1<<"\t"<<DiscoveryTime[u]<<"\t\t"<<FinishTime[u]<<"\t\t"<<Ancestor[u]<<endl;
}

vector<vector<int>> TransposeGraph(vector<vector<int>>& G)
{
    int n = G.size();
    vector<vector<int>> GT(n, vector<int>(n, 0));

    for(int u=0; u<n; u++)
    {
        for(int v=0; v<n; v++)
        {
            if(G[u][v] ==1)
                GT[v][u] = 1;
        }
    }
    return GT;
}

void DFS_VISIT_SCC(vector<vector<int>>& G, int u, vector<int>& component)
{
    color[u] = GRAY;
    component.push_back(u);

    for(int v=0; v<G[u].size(); v++)
    {
        if(G[u][v]==1 && color[v] == WHITE)
        {
            DFS_VISIT_SCC(G, v, component);
        }
    }
    color[u] = BLACK;
}

void findSCCs(vector<vector<int>>& G)
{
    DFS(G);

    int n = G.size();
    color.assign(n, WHITE);

    vector<vector<int>> GT = TransposeGraph(G);

    cout<<"Strongly connected Components: "<<endl;
    while(!finishStack.empty())
    {
        int u = finishStack.top();
        finishStack.pop();

        if(color[u] == WHITE)
        {
            vector<int> component;
            DFS_VISIT_SCC(GT, u, component);

            cout<<"{ ";
            for(int v:component)
                cout<<v<<", ";
            cout<<"}"<<endl;
        }
    }
}

int main()
{
    vector<vector<int>> G={
        {0,1,1,0, 0,0,0},
        {0,0,1,0, 0,1,0},
        {0,0,0,1, 0,0,0},
        {0,0,0,0, 0,0,0},
        {0,0,0,0, 0,0,0},
        {0,0,0,1, 1,0,0},
        {0,1,0,0, 0,1,0}
    };

    findSCCs(G);

    return 0;
}
