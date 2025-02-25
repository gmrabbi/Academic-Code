#include <iostream>
#define Max 3
using namespace std;

void Swap(int *a, int *b, int sz)
{
    int temp;
    for(int i=0; i<sz; i++)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

int main()
{
    int a[Max], b[Max];
    cout<<"Enter data for first array : "<<endl;
    for(int i=0; i<Max ; i++)
        cin>>a[i];

    cout<<"Enter data for second array : "<<endl;
    for(int i=0; i<Max ; i++)
        cin>>b[i];
    /*
    int temp;
    for(int i=0; i<Max; i++)
    {
        temp = *a[i];
        *a[i] = *b[i];
        *b[i] = *temp;
    }
    */
    Swap(a, b, Max);
    cout<<"first array "<<endl;
    for(int i=0; i<Max ; i++)
        cout<<a[i];
    cout<<endl;
    cout<<"second array "<<endl;
    for(int i=0; i<Max ; i++)
        cout<<b[i];

    return 0;
}
