#include <bits/stdc++.h>

using namespace std;

vector<int> x;
vector<vector<int>> G;
int n;
int m;
int soln = 0;

void NextValue(int k)
{
    while(true)
    {
        x[k] = (x[k]+1) % (m+1);
        if(x[k]==0)
            return;
        int j;
        for(j=0; j<n; j++)
        {
            if( (G[k][j] != 0) && (x[k] == x[j]) )
                break;
        }
        if(j==n)
            return;
    }
}

void mColoring(int k)
{
    while(true)
    {
        NextValue(k);
        if(x[k] == 0)
            return;
        if(k==n-1)
        {

            for(int i=0; i<n; i++)
                cout<<x[i]<<" ";
            cout<<endl;

            soln++;
        }
        else
            mColoring(k+1);
    }
}
int main()
{
    G={
        /*
        {0,1,0,0,1},
        {1,0,1,1,1},
        {0,1,0,1,0},
        {0,1,1,0,0},
        {1,1,0,0,0}
        */
        {0,1,1,0,0,0,1,0},
        {1,0,1,0,0,0,0,1},
        {1,1,0,1,0,0,0,0},
        {0,0,1,0,1,0,0,0},
        {0,0,0,1,0,1,0,0},
        {0,0,1,0,1,0,1,0},
        {1,0,1,0,0,1,0,1},
        {0,1,0,0,0,0,1,0}
    };

    n = G.size();
    x.resize(n);
    while(!soln)
    {
        m++;
        mColoring(0);
    }
    cout<<"Total "<<m<<" color needed."<<endl;

    return 0;
}
