// overloaded ‘+=’ assignment operator
#include <bits/stdc++.h>
using namespace std;

class Distance
{
private:
    int feet;
    float inch;
public:
    Distance(int ft=0 , float in=0.0): feet(ft), inch(in) { }
    void get_data()
    {
        cout<<"Enter inch : "; cin>>inch;
        cout<<"Enter feet : "; cin>>feet;
    }
    void Display()
    {
        cout<<feet <<"\' - "<<inch<<"\""<<endl;
    }
    void operator += (Distance) ;

};

void Distance::operator += (Distance d1)
{
    feet +=  d1.feet;
    inch +=  d1.inch;
    if(inch >= 12.0)
    {
        inch -= 12.0;
        feet++;
    }
    //return d1;
}


int main()
{
    Distance d1 , d2(11 , 6.25) , d3;
    d1.get_data();

    d1.Display();
    d2.Display();
    //d3.Display();

    d1 += d2;
    d1.Display();
    d2.Display();

    return 0;
}
