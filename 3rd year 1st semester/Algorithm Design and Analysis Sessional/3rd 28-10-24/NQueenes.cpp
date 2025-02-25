#include <bits/stdc++.h>

using namespace std;

vector<int> x;

bool Place(int k, int i)
{
    for(int j=0; j<=k-1; j++)
    {
        if((x[j]==i) || (abs(x[j]-i)==abs(j-k)) )
            return false;
    }
    return true;
}

void NQueens(int k, int n)
{
    for(int i=0; i<=n; i++)
    {
        if(Place(k, i))
        {
            x[k] = i;
            if(k == n)
            {
                for(int z: x)
                    cout<<z+1<<" ";
                cout<<endl;
            }
            else
                NQueens(k+1, n);
        }
    }
}

int main()
{
    int n;
    cout<<"Size of the Queens :";
    cin>>n;

    x.resize(n);
    NQueens(0, n-1);


    return 0;
}
