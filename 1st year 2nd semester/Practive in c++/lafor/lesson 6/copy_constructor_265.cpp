#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inch;
public:
    Distance(int f=0, float in=0.0):feet(f), inch(in) { }
    void showData()
    { cout<<feet<<"\' - "<<inch<<"\""<<endl; }


    void addDistance(Distance , Distance);
    Distance operator=(Distance);
    Distance operator+(Distance );
};

void Distance::addDistance(Distance d1 , Distance d2 )
{
    Distance temp ;
    feet = d1.feet + d2.feet;
    inch = d1.inch + d2.inch;
    if(inch > 12.0)
    {
        inch -=12.0;
        feet++;
    }
    //return temp;
}

Distance Distance::operator=(Distance d1)
{
    feet = d1.feet;
    inch = d1.inch;
    return *this;
}
Distance Distance::operator+(Distance d1 )
{
    Distance temp ;
    temp.inch += d1.inch + inch ;
    temp.feet += d1.feet + feet;
    return temp;
}

int main()
{
    Distance d1(4, 2.3);
    Distance d2 = d1;
    Distance d3;

    d3 = d1 + d2;

    d1.showData();
    d2.showData();
    d3.showData();

    return 0;
}
