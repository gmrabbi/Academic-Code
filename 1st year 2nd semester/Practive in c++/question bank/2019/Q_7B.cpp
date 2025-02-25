#include <bits/stdc++.h>

using namespace std;

class Counter
{
private:
    int data;
public:
    virtual void Display() = 0;
};
class Distance : public Counter
{
public:
    void Display()
    {
        cout<<"I am from Distance class."<<endl;
    }
};

class print:public Counter
{
public:
    void Display()
    {
        cout<<"I am from Print class."<<endl;
    }
};

int main()
{
    Counter *cu[2];
    Distance ds;
    print pr;
    cu[0] = &ds;
    cu[1] = &pr;

    cu[0]->Display();
    cu[1]->Display();


    return 0;
}
