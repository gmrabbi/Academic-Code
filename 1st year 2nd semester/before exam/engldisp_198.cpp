// engldisp.cpp
// demonstrates passing structure as argument

#include <iostream>

using namespace std;

struct Distance
{
    int feet;
    float inch;
};

void Display(Distance d)
{
    cout<<d.feet<<"\' - "<<d.inch<<"\""<<endl;
}

int main()
{
    Distance d1, d2;
    cout<<"Inch "; cin>>d1.inch;
    cout<<"Feet "; cin>>d1.feet;

    Display(d1);

    return 0;
}
