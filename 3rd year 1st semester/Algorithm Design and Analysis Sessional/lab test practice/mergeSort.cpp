#include <bits/stdc++.h>

using namespace std;

vector<int> b;
vector<int> a;

void marge(int low, int mid, int high)
{
    int h = low;
    int i = low;
    int j = mid+1;

    while((h<=mid) && (j<=high))
    {
        if(a[h]<=a[j])
        {
            b[i] = a[h];
            h++;
        }
        else
        {
            b[i] = a[j];
            j++;
        }
        i++;
    }
    if(h>mid)
    {
        for(int k=j; k<=high; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    else
    {
        for(int k=h; k<=mid; k++)
        {
            b[i] = a[k];
            i++;
        }
    }
    for(int k=low; k<=high; k++)
        a[k] = b[k];

}

void mergeSort(int low, int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergeSort(low, mid);
        mergeSort(mid+1, high);

        marge(low, mid, high);
    }
}

int main()
{

    int n = 10;
    // a.resize(n);
    b.resize(n);
    srand(time(0));

    for(int i=0; i<n; i++)
    {
        int rnum = (rand()%20)+1;
        a.push_back(rnum);
        cout<<rnum<<" ";
    }
    cout<<endl;


    for(auto i: a)
        cout<<i<<" ";
    cout<<endl;

    mergeSort(0, a.size()-1);

    for(auto i: a)
        cout<<i<<" ";
    cout<<endl;



    return 0;
}
