// ambigu.cpp
// demonstrates ambiguity in multiple inheritance
#include <iostream>
using namespace std;

class A
{
public:
    void show()
    {  cout<<"It's from A"<<endl; }
};

class B
{
public:
    void show()
    {  cout<<"It's from B"<<endl; }
};

class C:public A , public B
{
};

int main()
{
    C objc;
    objc.show();
    objc.A::show();
    objc.B::show();
}
