#include <bits/stdc++.h>
using namespace std;

class Distance
{
private:
    int feet;
    float inch;
public:
    Distance(): feet(0), inch(0.0) { }
    Distance(int f, float in): feet(f), inch(in) { }
    void Display()
    { cout<<feet<<"\' - "<<inch<<"\""<<endl; }

    Distance operator++(); //prefix
    Distance operator++(int); //postfix
    Distance operator+=(Distance);
};

Distance Distance::operator++()
{
    ++feet;
    ++inch;
    return *this;
}

Distance Distance::operator++(int)
{
    feet++;
    inch++;
    return *this;
}

Distance Distance::operator+=(Distance d1)
{

    feet += d1.feet;
    inch += d1.inch;
    if(inch>12.0)
    {
        inch-=12.0;
        feet++;
    }
    //cout<<"calling.."<<endl;
    return Distance(feet, inch);
}

int main()
{
    Distance d1(2, 4.5);
    d1.Display();

    Distance d2 = d1++;
    d2.Display();

    d1 += d2;
    d1.Display();
    return 0;

}
