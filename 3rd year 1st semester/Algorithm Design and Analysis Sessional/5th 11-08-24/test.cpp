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
    int v=a[m], i = m, j=p;
    while(i<=j)
    {
        while(a[i]<=v)
            i++;
        while(a[j]>v)
            j--;
        if(i<j) Interchange(a, i, j);
    }
    a[m] = a[j];
    a[j] = v;
    return j;
}

vector<int> a={14, 1, 3, 14, 1, 2, 20, 3, 11, 7};
void RQuickSort(int p, int q)
{
    if(p<q)
    {
        srand(time(0));
        if((q-p)>5)
            Interchange(a,rand()%(q-p+1)+p, p);
        int j = Partition(a, p, q);
        RQuickSort(p, j-1);
        RQuickSort(j+1, q);
    }
}

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
    srand(time(0));


    int n = 10;
    /*
    for(int i=0; i<n; i++)
        a.push_back((rand()%20)+1);
    */
    for(int i=0; i<a.size(); i++)
        cout<<a[i]<<" ";
    cout<<endl;

    // RQuickSort(0, a.size()-1);
    // QuickSort(0, a.size()-1);

    for(int i=0; i<a.size(); i++)
        cout<<a[i]<<" ";
    cout<<endl;




    return 0;
}


