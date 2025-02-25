#include <bits/stdc++.h>

using namespace std;

vector<int> x;

bool place(int k, int i)
{
    for(int j=0; j<=k-1; j++)
    {
        if( (x[j]==i) ||  ( abs(x[j]-i) == abs(j-k )) )
            return false;
    }
    return true;
}

void Nqueens(int k, int n)
{
    for(int i=0; i<=n; i++)
    {
        if(place(k, i))
        {
            // cout<<"k="<<k<<" i="<<i<<endl;
            x[k] = i;
            if(k==n)
            {
                // cout<<"here"<<endl;
                for(auto i: x)
                    cout<<i+1<<" ";
                cout<<endl;
            }
            else
                Nqueens(k+1, n);
        }
    }
}

int main()
{
    int n = 5;
    x.resize(n);

    Nqueens(0, n-1);

    return 0;
}
