#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<vector<int>>A={
        {0,3,8,INT_MAX,-4},
        {INT_MAX,0,INT_MAX,1,7},
        {INT_MAX,4,0,INT_MAX, INT_MAX},
        {2,INT_MAX,-5,0,INT_MAX},
        {INT_MAX,INT_MAX,INT_MAX,6,0}
    };

    int n= A.size();

    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(A[i][k] != INT_MAX && A[k][j]!= INT_MAX)
                    A[i][j] = min(A[i][j], A[i][k]+A[k][j]);
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}
