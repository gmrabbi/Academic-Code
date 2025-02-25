#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    virtual void show() = 0;
};
class Drive1: public Base
{
public :
    void show()
    {
        cout<<"Drive 1."<<endl;
    }
};

class Drive2: public Base
{
public:
    void show()
    {
        cout<<"Drive 2."<<endl;
    }
};

int main()
{
    Base* b[2];
    Drive1 drv1;
    Drive2 drv2;

    b[0] = &drv1;
    b[0] -> show();

    b[1] = &drv2;
    b[1] -> show();
    return 0;
}
