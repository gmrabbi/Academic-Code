#include <iostream>
using namespace std;

class Distance
{
protected:
    int data;
public:
    Distance(int a=0):data(a) { }
    void Display1()
    { cout<<"From Distance "<<data<<endl;  }
};

class Counter : protected Distance
{
protected:
    //int a;
public:
    Counter(int b=0):Distance(b) { }
    void Display()
    {
        Display1();
        cout<<"From Counter "<<data<<endl;
    }
};

int main()
{
    Counter cu(2);
//    cout<<cu.data<<endl;
    cu.Display();
}
