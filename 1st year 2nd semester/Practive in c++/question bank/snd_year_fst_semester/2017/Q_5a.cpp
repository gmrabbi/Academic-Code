#include <iostream>

using namespace std;
class G
{
public:
    void Display()
    {  cout<<" G "<<endl;  }
};

class A:public G
{
public:
    void Display()
    {  cout<<" A "<<endl;  }
};

class B:public G
{
public:
    void Display()
    {  cout<<" B "<<endl;  }
};

class C:  public A,  public B
{

};

int main()
{
    C cc;
    cc.A::Display();
    cc.B::Display();
}
