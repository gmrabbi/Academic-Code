#include <bits/stdc++.h>

using namespace std;

vector<int> w = {5,10,12,13,15,18};
int m = 30;
const int n = w.size();
vector<int> x;

void SumOfSub(int s, int k, int r)
{
    // cout<<"s="<<s<<" k="<<k<<" r="<<r<<" w[k]="<<w[k]<<endl;
    x[k] = 1;
    if(s+w[k] == m)
    {
        // cout<<"if part"<<endl;
        // cout<<"s="<<s<<" k="<<k<<" r="<<r<<" w[k]="<<w[k]<<endl;
        for(int i=0; i<=k; i++)
        {
            if(x[i])
                cout<<w[i]<<" ";
        }
        cout<<"\n--------------------\n"<<endl;
    }
    else if(s+w[k]+w[k+1]<=m)
    {
        // cout<<"if else part"<<endl;
        // cout<<"s="<<s<<" k="<<k<<" r="<<r<<" w[k]="<<w[k]<<endl;
        SumOfSub(s+w[k], k+1, r-w[k]);
        // cout<<"back here"<<endl;
    }
    if((s+r-w[k]>=m) && (s+w[k+1]<=m))
    {
        // cout<<"condition fail part"<<endl;
        // cout<<"s="<<s<<" k="<<k<<" r="<<r<<" w[k]="<<w[k]<<endl;
        x[k] = 0;
        SumOfSub(s, k+1, r-w[k]);
        // cout<<"back"<<endl;
    }
}

int main()
{
    x.resize(n);
    int sum = 0;
    for(int z:w)
        sum += z;
    SumOfSub(0,0,sum);

    return 0;
}
