#include <bits/stdc++.h>

using namespace std;

class Distance
{
private:
    int feet ;
    float inch;
public:
    Distance(int ft = 0 , float in=0.0):feet(ft), inch(in) { }

    void Display()
    { cout<<feet<<"\' - "<<inch<<"\""<<endl; }

    bool operator == (Distance);
    void add_Distance(Distance , Distance);
    Distance add_Distance(Distance);
    Distance operator += (Distance);
    friend Distance operator + (Distance , Distance );
};

bool Distance::operator==(Distance d)
{   return ((d.inch == inch) && (d.feet == feet))?true:false;   }

void Distance::add_Distance(Distance d1 , Distance d2)
{
    feet = d1.feet + d2.feet;
    inch = d1.inch + d2.inch;
    if(inch> 12.0)
    {
        feet++;
        inch -= 12.0;
    }
}

Distance Distance::add_Distance(Distance d1)
{
    inch += d1.inch;
    feet += d1.feet;

    if(inch>12.0)
    {
        feet++;
        inch -= 12.0;
    }
}

Distance Distance::operator+=(Distance d)
{
    inch += d.inch;
    feet += d.feet;
    return Distance(feet , inch);
}

Distance operator + (Distance d1 , Distance d2)
{
    Distance d3;
    d3.inch = d1.inch + d2.inch;
    d3.feet = d1.feet + d2.feet;

    if(d3.inch >= 12.0)
    {
        d3.feet++;
        d3.inch -= 12.0;
    }
    return Distance(d3.feet , d3.inch);
}

int main()
{
    Distance d1(2, 3.4) , d2(8, 11.3) , d3;

    d1.Display();
    d2.Display();

    if(d1 == d2)
        cout<<"d1 equal ..to d2"<<endl;
    else
        cout<<"d1 not equal to d2"<<endl;

    d3 = d1+d2;
    d3.Display();

    cout<<endl;

    d3.add_Distance(d1, d2);
    d3.Display();

    cout<<endl;

    d1.add_Distance(d2);
    d1.Display();

    d1 += d3;
    d1.Display();

}

///////////////////////////////
/*
class Distance
{
private :
    int feet;
    float inch;
public:
    Distance(int ft= 0 , float in = 0.0):feet(ft), inch(in) { }
    void add_Distance(Distance d1 , Distance d2);
};


}

int main()
{
    Distance d1(2, 3.4) , d2(8, 11.3) , d3;
    d3.add_Distance(d1, d2);
    d
}

void Distance::add_Distance(Distance d1 , Distance d2)
{
    feet = d1.feet + d2.feet;
    inch = d1.inch + d2.inch;

    if(inch >= 12.0)
    {
        feet++;
        inch -= 12.0;
    }

*/
