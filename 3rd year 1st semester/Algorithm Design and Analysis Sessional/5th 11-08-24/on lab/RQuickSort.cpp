#include <bits/stdc++.h>
using namespace std;
void Interchange(vector<int>& a, int i, int j)
{
    int p = a[i];
    a[i] = a[j];
    a[j] = p;
}

int Partition(vector<int>& a, int m, int p)
{
    int v = a[m];
    int i = m;
    int j = p;
    while(i<=j){
        while(a[i]<=v)
            i++;
        while(a[j]>v)
            j--;
        if(i<j)
            Interchange(a, i, j);
    }
    a[m] = a[j];
    a[j] = v;
    return j;
}
vector<int> a;
void RQuickSort(int p, int q)
{
    if(p<q){
        if((q-p)>5)
            Interchange(a, rand()%(q-p+1)+p, p);
        int j = Partition(a, p, q);
        RQuickSort(p, j-1);
        RQuickSort(j+1, q);
    }
}
vector<int> b ;
void QuickSort(int p, int q)
{
    if(p<q){
        int j = Partition(b, p, q);
        QuickSort(p, j-1);
        QuickSort(j+1, q);
    }
}

int main()
{
    int n=15000;
    srand(time(0));
    for(int i=0; i<n; i++)
        a.push_back((rand()%200)+1);

    for(int i=0; i<a.size(); i++)
    {
        b.push_back(a[i]);
    }

    cout<<"Total Data: "<<n<<endl;
    auto Start = chrono::high_resolution_clock::now();
    //RQuickSort(0, a.size()-1);
    QuickSort(0, b.size()-1);
    auto End = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = End - Start;
    cout<<"Total Time for QuickSort: "<<duration.count()<<" millSecond"<<endl;

    auto Startr = chrono::high_resolution_clock::now();
    RQuickSort(0, a.size()-1);
    //QuickSort(0, a.size()-1);
    auto Endr = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> durationr = Endr - Startr;
    cout<<"Total Time for RQuickSort: "<<durationr.count()<<" millSecond"<<endl;

    return 0;
}

