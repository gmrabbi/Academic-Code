#include <iostream>

using namespace std;

class Distance
{
    int feet;
    float inches;
public:
    Distance();
    Distance(int f, float i);
    void DisplayDistance();
    Distance operator +=(Distance);
    Distance operator ++();
    Distance operator ++(int);
    friend Distance operator*(Distance, int);
};
Distance::Distance()
{
    feet = 0;
    inches = 0.0;
}

Distance::Distance(int f, float i)
{
    feet = f;
    inches = i;
}

void Distance::DisplayDistance()
{ cout<<feet<<"\' - "<<inches<<"\""<<endl; }

Distance Distance::operator+=(Distance d)
{
    inches += d.inches;
    feet += d.feet;
    if(inches>= 12.0)
    {
        inches -= 12.0;
        feet+=1;
    }
    return *this;
}

Distance Distance::operator++()
{
    feet++;
    inches++;
    if(inches>= 12.0)
    {
        inches -= 12.0;
        feet+=1;
    }
    return *this;
}

Distance Distance::operator++(int)
{
    feet++;
    inches++;
    if(inches>= 12.0)
    {
        inches -= 12.0;
        feet+=1;
    }
    return *this;
}

Distance operator*(Distance d2, int d1)
{
    Distance temp;
    temp.inches = d1 * d2.inches;
    temp.feet = d1 * d2.feet;
    if(temp.inches >= 12.0)
    {
        temp.feet++;
        temp.inches -= 12.0;
    }
    return temp;
}

int main()
{

    Distance d1(12, 10.9), d2(4, 2.3), d3;
    d1.DisplayDistance();
    d2.DisplayDistance();
    d3.DisplayDistance();

    cout<<endl;
    d2 += d1;
    d3 += d2;
    d1.DisplayDistance();
    d2.DisplayDistance();
    d3.DisplayDistance();


    cout<<endl;
    d1 = d2 * 10;
    d1.DisplayDistance();
    d2.DisplayDistance();
    d3.DisplayDistance();

    return 0;
}


