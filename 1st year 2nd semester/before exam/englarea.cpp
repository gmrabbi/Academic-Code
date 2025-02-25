// englarea.cpp
// demonstrates nested structures
#include <iostream>

using namespace std;

struct Distance
{
    int feet;
    float inch;
};

struct Room
{
    Distance height;
    Distance legth;
};

void Display(struct Distance d)
{  cout<<d.feet<<"\' - "<<d.inch<<"\""<<endl;  }

int main()
{
    Room rm1;
    cout<<"Feet (height) : "; cin>>rm1.height.feet;
    cout<<"Inch (height) : "; cin>>rm1.height.inch;
    cout<<endl;
    cout<<"Feet (length) : "; cin>>rm1.legth.feet;
    cout<<"Inch (length) : "; cin>>rm1.legth.inch;
    cout<<endl;

    int ft = rm1.height.feet + rm1.legth.feet;
    float inc = rm1.height.inch + rm1.legth.inch;
    if(inc>=12.0)
    {
        inc -= 12.0;
        ft +=1;
    }

    cout<<"Total Distance : "<<endl;
    Distance d3 = {ft , inc};
    //cout<<"Feet : "<<ft<<endl;
    //cout<<"Inch : "<<inc<<endl;

    Display(d3);

    return 0;
}
