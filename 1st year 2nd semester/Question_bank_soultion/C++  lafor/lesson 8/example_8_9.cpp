#include <bits/stdc++.h>
using namespace std;

class Distance
{
private:
    int feet;
    float inch;
public:
    Distance(int f=0, float in=0.0):feet(f), inch(in) { }
    void Display()
    { cout<<feet<<"\' - "<<inch<<"\""<<endl; }
    //void operator++(int);
    Distance operator++(int);
};
/*
void Distance::operator++(int)
{
    feet++;
    inch++;
}
*/
Distance Distance::operator++(int)
{
    feet++;
    inch++;
    return *this;
}

int main()
{
    Distance d1(3, 4.5), d2;
    d1.Display();
    d1++;
    d1.Display();

    d2 = d1++;
    d1.Display();
    d2.Display();
    return 0;
}
