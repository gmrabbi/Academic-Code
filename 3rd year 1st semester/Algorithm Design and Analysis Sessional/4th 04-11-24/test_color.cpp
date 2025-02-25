#include <bits/stdc++.h>

using namespace std;

vector<int> x;
vector<vector<int>> G;
int m=0;
int n;
int soln = 0;

void NextValue(int k)
{
    while (true)
    {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
            return;

        int j;
        for (j = 0; j < n; j++)
        {
            if (G[k][j] != 0 && x[k] == x[j])
                break;
        }
        if (j == n)
            return;
    }
}

void mColoring(int k)
{
    while (true)
    {
        NextValue(k);
        if (x[k] == 0)
            return;
        if (k == n - 1)
        {
            for (int i = 0; i < n; i++)
            {
                cout << x[i] << " ";
            }
            cout << endl;
            soln++;
        }
        else
            mColoring(k + 1);
    }
}

int main()
{
    //cout << "How many vertices: " << endl;
    //cin >> n;

    n = 5; // num of vertex
    // resize G and initialize x
    G.resize(n, vector<int>(n));
    x.resize(n, 0);


    // example graph input
    G = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 0},
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };

    while(!soln)
    {
        m++;
        mColoring(0);
    }

    cout<<"total color need: "<<m<<endl;

    return 0;
}
