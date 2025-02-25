#include <bits/stdc++.h>

using namespace std;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

vector<int> color;
vector<int> Ancestor;
vector<int> DiscoveryTime;
vector<int> FinishTime;
stack<int> finishStack;
vector<int> FinishVertex;
int TimeCount;

void VISIT_DFS(vector<vector<int>>&G, int u)
{
    color[u] = GRAY;
    DiscoveryTime[u] = ++TimeCount;

    for(int v=0; v<G[u].size(); v++)
    {
        if(G[u][v] == 1 && color[v]==WHITE)
            {
                Ancestor[v] = u;
                VISIT_DFS(G, v);
            }
    }
    FinishTime[u] = ++TimeCount;
    color[u] = BLACK;
    finishStack.push(u);
    FinishVertex.push_back(u);
}

void DFS(vector<vector<int>>& G)
{
    int n = G.size();
    color.assign(n, WHITE);
    Ancestor.assign(n, -1);
    DiscoveryTime.assign(n, 0);
    FinishTime.assign(n, 0);
    // finishStack.();
    FinishVertex.clear();

    for(int u=0; u<n; u++)
    {
        if(color[u] == WHITE)
            VISIT_DFS(G, u);
    }

    cout<<"vertex\tDiscoveryTime\tFinishTime\tAncestor."<<endl;
    for(int u=0; u<n; u++)
        cout<<u+1<<"\t\t"<<DiscoveryTime[u]<<"\t\t"<<FinishTime[u]<<"\t\t"<<Ancestor[u]+1<<endl;
}

vector<vector<int>> TransposeGraph(vector<vector<int>>& G)
{
    int n = G.size();
    vector<vector<int>> GT(n, vector<int>(n, 0));

    for(int u=0; u<n; u++)
    {
        for(int v=0; v<G[u].size(); v++)
        {
            if(G[u][v])
                GT[v][u] = 1;
        }
    }
    return GT;
}

void DFS_VISIT_SCC(vector<vector<int>>&G ,int u,vector<int>& component)
{
    color[u] = GRAY;
    component.push_back(u);

    for(int v=0; v<G[u].size(); v++)
    {
        if(G[u][v] == 1 && color[v]==WHITE)
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
    cout<<"Strongly connected Components:"<<endl;

    while(!finishStack.empty())
    {
        int u = finishStack.top();
        finishStack.pop();

        if(color[u]==WHITE)
        {
            vector<int> component;
            DFS_VISIT_SCC(GT, u, component);

            cout<<"{ ";
            for(auto &i: component)
                cout<<i<<", ";
            cout<<"}"<<endl;
        }
    }
}

vector<int> Topological_sort(vector<vector<int>>& G)
{
    int n = G.size();
    color.assign(n, WHITE);
    Ancestor.assign(n, -1);
    DiscoveryTime.assign(n, 0);
    FinishTime.assign(n, 0);
    TimeCount = 0;

    DFS(G);
    reverse(FinishVertex.begin(), FinishVertex.end());
    return FinishVertex;
}

int main()
{
    vector<vector<int>> G={
        {0,1,0,0, 0,0,0,0},
        {0,0,1,0, 0,0,0,0},
        {0,0,0,1, 1,0,0,0},
        {1,0,0,0, 0,0,0,0},

        {0,0,0,0, 0,1,0,0},
        {0,0,0,0, 0,0,1,0},
        {0,0,0,0, 1,0,0,1},
        {0,0,0,0, 0,0,0,0},
    };

    findSCCs(G);
    // DFS(G);

    cout<<endl<<endl;

    vector<vector<int>> G1=
    {
        {0,1,1,0, 0,0,0},
        {0,0,1,0, 0,1,0},
        {0,0,0,1, 0,0,0},
        {0,0,0,0, 0,0,0},
        {0,0,0,0, 0,0,0},
        {0,0,0,1, 1,0,0},
        {0,1,0,0, 0,1,0}
    };
    vector<int> topological = Topological_sort(G1);
    for(int i: topological)
        cout<<i<<" ";

    return 0;
}
