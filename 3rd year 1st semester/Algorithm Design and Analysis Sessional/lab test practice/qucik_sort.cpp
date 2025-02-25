#include <bits/stdc++.h>

using namespace std;

void interchange(vector<int>& a, int i, int j)
{
    int p = a[i];
    a[i] = a[j];
    a[j] = p;
}

int partition(vector<int>& a, int m, int p)
{
    int v = a[m];
    int i = m;
    int j = p;

    while(i<=j)
    {
        while(a[i]<=v)
            i++;
        while(a[j]>v)
            j--;
        if(i<j)
            interchange(a, i, j);
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
        int j = partition(a, p, q);
        QuickSort(p, j-1);
        QuickSort(j+1, q);
    }
}

int main()
{
    srand(time(0));
    int n=1000;

    for(int i=0; i<n; i++)
        a.push_back((rand()%100) +1 );
    /*
    for(auto i: a)
        cout<<i<<" ";
    cout<<endl;
    */

    auto start = chrono::high_resolution_clock::now();
    QuickSort(0, n-1);
    auto End = chrono::high_resolution_clock::now();

    for(auto i: a)
        cout<<i<<" ";
    cout<<endl;

    chrono::duration<double, milli> duration = End - start;
    cout<<"Total time taken: "<<duration.count()<<endl;



    return 0;
}


