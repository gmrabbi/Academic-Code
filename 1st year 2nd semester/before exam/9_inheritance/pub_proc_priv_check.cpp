#include <iostream>
using namespace std;

class A
{
private:
    int a1=0;
protected:
    int a2=1;
public:
    void Display()
    { cout<<a1<<" "<<a2<<endl; }
};

class B: protected A
{
private:
    int b1=2;
protected:
    int b2=3;
public:
    void Display1()
    {
        cout<<a2<<endl;
        cout<<b1<<" "<<b2<<endl;
    }
};

class C: private B
{
private:
    int c1=4;
protected:
    int c2=5;
public:
    void Display2()
    {
        cout<<a2<<endl;
        cout<<b2<<endl;
        cout<<c1<<" "<<c2<<endl;
    }
};
class D: private C
{
private:
    int D1=4;
protected:
    int D2=5;
public:
    void Display3()
    {
        cout<<a2<<endl;
        cout<<b2<<endl;
        cout<<c1<<" "<<c2<<endl;
        cout<<D1<<" "<<D2<<endl;
    }
};

int main()
{
    A aa;
    B bb;
    C cc;

    aa.Display();
    cout<<endl;
    //bb.Display();
    bb.Display1();
    cout<<endl;
    //cc.Display();
    //cc.Display1();
    cc.Display2();

    return 0;
}
