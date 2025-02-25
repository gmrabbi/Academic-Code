#include <bits/stdc++.h>

using namespace std;

vector<int> x;
vector<int> w = {5,10, 12, 13, 15, 20};
int m = 30;

void SumOfSub(int s, int k, int r)
{
    x[k] = 1;
    if(s+w[k] == m)
    {
        for(int i=0; i<=k; i++)
        {
            if(x[i])
                cout<<w[i]<<" ";
        }
        cout<<endl;
    }
    else if(s+w[k]+w[k+1] <= m)
        SumOfSub(s+w[k], k+1, r-w[k]);

    if((s+(r-w[k]))>=m && (s+w[k+1]<=m))
    {
        x[k] = 0;
        SumOfSub(s, k+1, r-w[k]);
    }
}

int main()
{
    int sum = 0;
    x.resize(w.size());
    for(auto i: w)
        sum += i;
    // cout<<sum<<endl;

    SumOfSub(0,0, sum);



    return 0;
}

