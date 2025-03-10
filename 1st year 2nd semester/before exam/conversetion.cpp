/*
#include <iostream>

using namespace std;

class Distance
{
private:
    int feet;
    float inch;
public:
    Distance(int f=0, float i=0.0):feet(f),inch(i) { }
    void Display()
    { cout<<feet<<"\' - "<<inch<<"\" "<<endl; }
    Distance(float a)
    {
        feet = int(a);
        inch = 12*(a-feet);
    }
    operator float()
    {
        return feet+(inch/12);
    }

};

int main()
{
    Distance d1(1, 2.3);
    float m;
    d1.Display();

    Distance d2 = 23.44F;
    d2.Display();

    m = d1;
    cout<<m<<endl;

    return 0;
}

*/

#include <iostream>
#define MTF 3.2808
using namespace std;

class Distance
{
private:
    int feet;
    float inch;
public:
    Distance(int f, float i):feet(f),inch(i) { }
    void Display()
    {  cout<<feet<<"\' - "<<inch<<"\""<<endl; }
    Distance(float a)
    {
        a = a * MTF;
        feet = int(a);
        inch = 12*(a - feet);
    }
    operator float()
    {
        return (feet+(inch/12))/MTF;
    }

};

int main()
{
    Distance d1(5, 10.25);
    d1.Display();

    Distance d2 = 2.35F;
    d2.Display();

    float m;
    m = d1;
    cout<<m<<endl;

    return 0;
}


















