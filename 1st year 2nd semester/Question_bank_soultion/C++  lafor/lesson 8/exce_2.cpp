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
    {  cout<<feet<<"\' - "<<inch<<"\""<<endl;  }
    Distance operator+=(Distance);
};

Distance Distance::operator+=(Distance d1)
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

int main()
{
    Distance d1(20, 5.4) , d2(10, 8.1);
    d1.Display();
    d2.Display();

    Distance d3 = d1 += d2;
    cout<<"--------"<<endl;
    d1.Display();
    d2.Display();
    d3.Display();

    return 0;
}
