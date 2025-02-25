#include <bits/stdc++.h>

using namespace std;

void Interchange(vector<int>& a, int i, int j)
{
    int p = a[i];
    a[i] = a[j];
    a[j] = p;
}

int Partition(vector<int>&a, int m, int p)
{
    int v = a[m];
    int i = m;
    int j = p;
    while(i<=j)
    {
        while(a[i]<=v)
            i++;
        while(a[j] > v)
            j--;
        if(i<j)
            Interchange(a, i, j);
    }
    a[m] = a[j];
    a[j] = v;
    return j;
}

vector<int> a;
void QuickSort(int p, int q)
{
    if(p<q)
    {
        int j = Partition(a, p, q);

        QuickSort(p, j-1);
        QuickSort(j+1, q);
    }
}

int main()
{

    int n = 5;
    // a.resize(n);

    srand(time(0));
    for(int i=0; i<n; i++)
    {
        int num = (rand() % 30) + 1;
        a.push_back(num);
    }

    for(int i=0; i<a.size(); i++)
        cout<<a[i]<<" ";
    cout<<endl;

    QuickSort(0, a.size()-1);

    for(int i=0; i<a.size(); i++)
        cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}
