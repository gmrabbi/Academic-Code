// virtpure.cpp
// pure virtual function
#include <iostream>
using namespace std;

class Base
{
public:
    virtual void show()=0;
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
    void show2()
    { cout<<"Drive 22"<<endl; }
};

int main()
{
    Base *b[2];
    Drive1 div1;
    Drive2 div2;

    b[0]= &div1;
    b[1] = &div2;

//    b.show();
    b[0]->show();
    b[1]->show();
    //div2.show();
    return 0;
}
