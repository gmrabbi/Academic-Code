#include <bits/stdc++.h>
using namespace std;

void order(int& a , int& b)
{
    if(a>b)
    {
        a = a+b;
        b = a-b;
        a = a-b;
    }

}


int main()
{
    int a=10 , b=30, c=40 ,d=20;
    order(a,b);
    order(c, d);
    cout<<a<<b<<c<<d;
}
