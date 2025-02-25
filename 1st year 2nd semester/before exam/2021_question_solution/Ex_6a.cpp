#include <iostream>
using namespace std;

class Counter
{
private:
    int cnt;
public:
    Counter():cnt(0) { }
    virtual void Display() = 0;
//    { cout<<"This is Base class"<<endl; }
};

class Drive1:public Counter
{
public:
    Drive1():Counter() { }
    void Display()
    {
        cout<<"Drive 1"<<endl;
    }
};

class Drive2:public Counter
{
public:
    Drive2():Counter() { }
    void Display()
    {
        cout<<"Drive 2"<<endl;
    }
};

class gnd_drv:public Drive1, public Drive2
{
public:
    void Display()
    {
        cout<<"Grand child."<<endl;
    }
};

int main()
{
    Counter *c;
    Drive1 d1;
    Drive2 d2;
//    gnd_drv gd;

    //c -> Display();

    c = &d1;
    c -> Display();

    c = &d2;
    c -> Display();

//    c = &gd;
//    c.Display();
}







