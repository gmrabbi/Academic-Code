#include <iostream>

using namespace std;

class AA
{
protected:
    int a;
public:
    AA(int x=0):a(x) { }
    virtual void show() = 0;
};

class BB:public AA
{
public:
    BB(int y=0):AA(y) { }
    void show()
    {  cout<<"From B -> a = "<<a<<endl;  }
};

class CC:public AA
{
public:
    CC(int y=0):AA(y) { }
    void show()
    {  cout<<"From C -> a = "<<a<<endl;  }
};

int main()
{
    AA *aa;
    BB bb;
    CC cc;

    aa = &bb;
    aa->show();
    aa = &cc;
    aa->show();

    return 0;
}


