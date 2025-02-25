#include <bits/stdc++.h>
using namespace std;

/*
//// factorial number
int fact(int n)
{
    if (n == 1)
        return 1;
    else
        return n*fact(n-1);
}

int main()
{
    cout<<fact(5);

    return 0 ;
}
*/

///fibonacci number
int fibo(int n)
{
    if(n == 0 || n == 1 )
        return n;
    else
        return fibo(n-1)+fibo(n-2);
}

int main()
{
    int n = 0;
    while(n<10)
    {
        cout<<fibo(n)<<" ";
        n++;
    }
    return 0;
}
