// notvirt.cpp
// normal functions accessed from pointer
#include <iostream>
using namespace std;

class Base
{
public:
    virtual void show()
    { cout<<"base"<<endl; }
};
class Drive1:public Base
{
public:
    void show()
    { cout<<"Drive 1"<<endl; }
};
class Drive2:public Base
{
public:
    void show()
    { cout<<"Drive 2"<<endl; }
};


int main()
{
    Base *p;
    Drive1 div1;
    Drive2 div2;

    //div1.show();
    //div2.show();


    p = &div1;
    p->show();

    p = &div2;
    p->show();

    char c[20];
    gets(c);
    puts(c);
    //cout<<c<<endl;
    return 0;
}










