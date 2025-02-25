#include <iostream>

using namespace std;

void zeroSmaller(int &a , int &b)
{
    if(a>b)
        b=0;
    else
        a=0;
}

int main()
{
    int a = 2 , b=4;
    cout<<a<<" "<<b<<endl;
    zeroSmaller(a, b);
    cout<<a<<" "<<b<<endl;

    return 0;
}
