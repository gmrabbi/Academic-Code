#include <bits/stdc++.h>
using namespace std;

class X
{
    int a, b;
public:
    X(int i, int j) { a=i ; b=j;}
    operator int()
    { return (a+b); }
};

int main()
{
    X x(2, 3);
    int sum;
    sum = x;
    cout<<sum<<endl;
    return 0;
}
