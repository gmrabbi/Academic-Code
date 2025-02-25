// xofxref.cpp
// copy constructor: X(X&)
#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inch;
public:
    Distance():feet(0), inch(0.0)
    { cout<<"constructor without arg"<<endl; }
    Distance(int f, float i):feet(f),inch(i)
    { cout<<"constructor with arg"<<endl; }
    ~Distance()
    {  cout<<"Distractor0"<<endl;  }

    void Display()
    {  cout<<feet<<"\' - "<<inch<<"\""<<endl;  }
    Distance(Distance& d)
    {
        feet = d.feet;
        inch = d.inch;
        cout<<"copy constructor"<<endl;
    }
    Distance operator=(Distance& d)
    {
        feet = d.feet;
        inch = d.inch;
        cout<<" = operator"<<endl;
    }

};

int main()
{
    Distance d1(11, 10.2), d2;
    d1.Display();
    d2.Display();

    Distance d3(d1);

    d2 = d1;
    d3.Display();

    return 0;
}





