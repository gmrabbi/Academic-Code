#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    virtual void show()
    {
        cout<<"This is from Base."<<endl;
    }
};

class Drive1 : public Base
{
public:
    void show()
    {
        cout<<"This is from Drive 1."<<endl;
    }
};


class Drive2 : public Base
{
public:
    void show()
    {
        cout<<"This is from Drive2."<<endl;
    }
};

int main()
{
    Drive1 dri1;
    Drive2 dri2;
    Base* ptr;

    ptr = &dri1;
    ptr->show();

    ptr = &dri2;
    ptr->show();
    return 0;
}
