#include <bits/stdc++.h>

using namespace std;

vector<int> x;
vector<vector<int>> G;
int n=0;

void NextValue(int k)
{
    while(true)
    {
        x[k] = (x[k]+1) % (n+1);
        if(x[k] == 0)
            return;
        if(G[x[k-1]][x[k]] != 0)
        {
            int j;
            for(j=0; j<k-1; j++ )
            {
                if(x[j] == x[k])
                    break;
            }
            if(j==k)
            {
                if((k<n-1) || (k==n-1))
                    return;
            }
        }
    }
}

void Hamiltonian(int k)
{
    while(true)
    {
        NextValue(k);
        if(x[k]==0)
            return;
        if(k==n-1)
        {
            for(int i=0; i<n; i++)
            {
                cout<<x[i]<<" ";
            }
            cout<<endl;
        }
        else
        {
            Hamiltonian(k+1);
        }
    }
}

int main()
{
    // how many vertices
    n = 5;
    G = {
        {0,1,0,0,1},
        {1,0,1,1,1},
        {0,1,0,1,0},
        {0,1,1,0,1},
        {1,1,0,0,0}
    };

    Hamiltonian(0);


    return 0;
}

