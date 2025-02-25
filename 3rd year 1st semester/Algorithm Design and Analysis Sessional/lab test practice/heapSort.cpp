#include <bits/stdc++.h>

using namespace std;

void heapify(vector<int>& a,int n,int i)
{
    int l= 2*i +1;
    int r = 2*i+2;
    int large = i;

    if(l<n && a[l]>a[i])
        large = l;
    if(r<n && a[r] > a[large])
        large = r;

    if(large != i)
    {
        swap(a[i], a[large]);
        heapify(a, n, large);
    }
}

void buildheap(vector<int>& a, int n)
{
    for(int i=(n/2)-1; i>=0; i--)
        heapify(a, n, i);
}
void HeapSort(vector<int>& a, int n)
{
    buildheap(a, n);
    for(int i=n-1; i>=0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main()
{
    vector<int> A;

    srand(time(0));

    for(int i=0; i<10; i++)
    {
        A.push_back((rand()%100)+1);
    }

    for(auto i: A)
        cout<<i<<" ";
    cout<<endl;

    HeapSort(A, A.size());

    for(auto i: A)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}
