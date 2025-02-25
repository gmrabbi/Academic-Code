#include <bits/stdc++.h>
using namespace std;

class X
{
    int x ;

public:
    X(int n = 0) : x(n) { }
    void get_data()
    {
        cout<<"Enter the value : "; cin>>x;
    }
    void show_data()
    {
        cout<<x<<endl;
    }
    int subtract(X n)
    {
        return (n.x - x);
    }
};


int main()
{
    X x1(5), x2,x3 ;
    x2.get_data();

    x1.show_data();
    x2.show_data();
    x3.show_data();

    x3 = x1.subtract(x2);
    x3.show_data();

    return 0;

}
