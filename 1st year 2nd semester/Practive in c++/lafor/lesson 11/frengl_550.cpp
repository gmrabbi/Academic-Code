#include <bits/stdc++.h>

using namespace std;

class Distance
{
private:
    int feet ;
    float inch;
public:
    Distance()
        { feet = 0; inch = 0.0 ;}

    Distance(int f ,float in)
        { feet = f; inch = in ;}
    Distance(float fltfeet)
    {
        feet = int(fltfeet);
        inch = 12*(fltfeet - feet);
    }
    void show()
    {  cout<<feet <<"\' - "<<inch<<"\"";  }
    Distance operator+(Distance);
    Distance operator+(float);
    //friend Distance operator+ (Distance , Distance);
    //friend Distance operator+(float , Distance);
};
//----------   + operator overloading

Distance Distance::operator+(Distance d1)
{
    feet += d1.feet;
    inch += d1.inch;
    if(inch>12.0)
    {
        feet++;
        inch -= 12.0;
    }
    return *this;
}
Distance Distance::operator+(float a)
{
    feet += a;
    inch += a;
    return *this;
}

/*
// overloading using friend function

Distance operator+(Distance d1 , Distance d2)
{
    int f = d1.feet + d2.feet;
    float i = d1.inch + d2.inch;
    if(i>12.0)
    { f++; i -= 12.0; }
    return Distance(f, i);
}

Distance operator+(float a , Distance d1)
{
    int feet = a + d1.feet;
    float inch = a + d1.inch;
    if(inch > 12.0)
    {
        inch -= 12.0;
        feet++;
    }
    return Distance(feet , inch);
}
*/
int main()
{
    Distance d1(2.3);
    //Distance d2(4, 1.25);
    Distance d2( 1.25);
    Distance d3;
    cout<<"\nd1 = "; d1.show() ;//<<endl;
    cout<<"\nd2 = "; d2.show() ;//<<endl;
    //d3 = d2+d1;
    //d3 = d1 + d2;
    d3 =  10.0 + d2;
    cout<<"\nd3 = "; d3.show() ;
    return 0;
}
