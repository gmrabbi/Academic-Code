#include <iostream>
using namespace std;

class B1
{
    int b1;
public:
    B1() { b1 = 2111; }
    virtual void display()
    {
        cout<<b1<<"\n";
    }
};

class B2
{
    int b2;
public:
    B2() {b2 = 2112; }
    virtual void display()
    {
        cout<<b2<<"\n";
    }
};

class D: virtual public B2, virtual public B1
{
    //nothing here
};

main()
{
    D d;
    d.display();
    d.B1::display();
    d.B2::display();
}
