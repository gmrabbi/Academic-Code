#include <iostream>

using namespace std;

class X
{
    int a, b;
public:
    X(int i, int j) {a=i, b=j; }
    //class to basic
    operator int()
    { return a*b; }
    //basic to class
    X(int x)
    {
        a = x/2;
        b = x/3;
    }
    void Display()
    {  cout<<"a="<<a<<"\nb="<<b<<endl;  }
};

int main()
{
    X obj(2, 3);
    int a ;
    //class to basic
    a = obj;
    cout<<a<<endl;

    //basic to class
    int c = 9;
    X obj1(1,2);
    obj1 = c;
    obj1.Display();
}
