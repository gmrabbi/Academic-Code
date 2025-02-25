// nofri.cpp
// limitation to overloaded + operator

#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inch;
public:
    Distance():feet(0),inch(0.0) { }
    Distance(int ft, float in):feet(ft),inch(in) { }
    Distance(float a)
    {
        feet = int(a);
        inch = 12*(a-feet);
    }
    void Display()
    {  cout<<feet<<"\' - "<<inch<<"\""<<endl; }
    /*
    Distance operator+(Distance d)
    {
        int f = feet + d.feet;
        float i = inch + d.inch;
        if(i>=12.0)
        {
            f++;
            i-=12.0;
        }
        return Distance(f , i);
    }

     friend Distance operator+(float f, Distance d)
    {
        Distance temp;
        temp.feet = d.feet + f;
        temp.inch = d.inch + f;
        if(temp.inch>=12.0)
        {
            temp.inch-=12.0;
            temp.feet++;
        }
        return temp;
    }
    */

    friend Distance operator+(Distance d1, Distance d2)
    {
        Distance temp;
        int f = d1.feet + d2.feet;
        int i = d1.inch + d2.feet;
        if(i>=12.0)
        {
            i-=12.0;
            f++;
        }
        return Distance(f, i);
    }
};



int main()
{
    Distance d1 = 2.5, d2, d3;
    d2 = 1.25;

    cout<<"d1 = "; d1.Display();
    cout<<"d2 = "; d2.Display();
    cout<<"d3 = "; d3.Display();
    cout<<endl;
    //d3 = d1 + 10.0 ;
    d3 = 10.0 + d1;
    cout<<"d3 = "; d3.Display();
    cout<<endl;

    return 0;
}




