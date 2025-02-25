#include <iostream>
using namespace std;

class Base
{
public:
    virtual void show() = 0;
};

class Drive1 : public Base
{
public:
    void show()
    {
        cout<<"Drive 1 "<<endl;
    }
};

class Drive2 : public Base
{
public:
    void show()
    {
        cout<<"Drive 2 "<<endl;
    }
};

int main()
{
    Base *arr[2];
    Drive1 dv1;
    Drive2 dv2;

    arr[0] = &dv1;
    arr[1] = &dv2;

    arr[0] -> show();
    arr[1] -> show();

    return 0;
}
