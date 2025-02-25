#include <iostream>
using namespace std;

class Base
{
public:
    virtual void show()
    {    cout<<"Base "<<endl;  }
};

class D1 : public Base
{
    public:
    void show()
    {  cout<<"Drive 1 "<<endl;  }
};

class D2 : public Base
{
public:
    void show()
    {  cout<<"Drive 2"<<endl;  }
};

int main()
{
    D1 dv1;
    D2 dv2;
    Base* ptr;

    ptr = &dv1;
    ptr -> show();

    ptr = &dv2;
    ptr ->show();

    return 0;
}
