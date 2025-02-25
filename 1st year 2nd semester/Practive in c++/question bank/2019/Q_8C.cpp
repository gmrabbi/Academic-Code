/*
What is a conversion function?

*/
//class to Basic

#include <bits/stdc++.h>
using namespace std;

class X
{
    int a, b;
public:
    X(int i , int j){ a=i;  b=j;}
    operator int()
    { return (a*b); }
};

int main()
{
    int a;
    X x(2, 3);
    a = x;
    cout<<a<<endl;
    return 0;
}
