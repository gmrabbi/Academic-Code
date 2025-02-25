#include <bits/stdc++.h>
#define  MTF 3.28
using namespace std;

class Distance
{
private:
    int feet ;
    float inch;
    //const float MTF ;
public:
    //Distance():MTF(1250/381) { }
    Distance(int f=0 , float in=0.0):feet(f),inch(in){ }
    Distance(float meter)
    {
        float fracfeet = meter*MTF;
        feet = int(fracfeet);
        inch = 12*(fracfeet - feet);
    }
    void Display()
    { cout<<feet<<"\' - "<<inch<<"\""<<endl;  }

    operator float()
    {
        float fracfeet = inch/12;
        fracfeet += float(feet);
        return fracfeet/MTF;
    }

};

int main()
{
    // basic to class
    Distance d1(3, 2.4);
    d1.Display();
    //Distance d2 ;
    float meter = 10.34F;
    Distance d2 = meter;
    d2.Display();

    //class to basic
    float mtr;
    Distance d3(12, 2.34);
    mtr = d3;
    cout<<"Meter : "<<mtr<<endl;
}

