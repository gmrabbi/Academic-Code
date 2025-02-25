#include <bits/stdc++.h>

using namespace std;

vector<int> w = {5, 10, 12,13, 15,18};
int n = w.size();
vector<int> x;
int m = 30;

void SumofSubset(int s, int k, int r)
{
    x[k] = 1;
    if(s+w[k] == m)
    {
        for(int z=0; z<=k; z++)
        {
            if(x[z])
                cout<<w[z]<<" ";
        }
        cout<<endl;
    }
    else if(s+w[k]+w[k+1]<=m)
        SumofSubset(s+w[k], k+1, r-w[k]);
    if((s+r-w[k]>=m) && (s+w[k+1]<=m))
    {
        x[k] = 0;
        SumofSubset(s,k+1, r-w[k]);
    }
}

int main()
{
    x.resize(n);
    int sum=0;
    for(int k: w)
        sum += k;
    cout<<"Summation: "<<sum<<endl;
    SumofSubset(0, 0, sum);

    return 0;
}
