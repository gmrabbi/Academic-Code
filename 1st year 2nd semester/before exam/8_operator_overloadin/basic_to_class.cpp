#include <iostream>

using namespace std;

class Distance
{
private:
    int feet;
    float inch;
public:
    Distance():feet(0), inch(0.0) { }
    Distance(int ft, float in):feet(ft),inch(in) { }
    Distance(float a)
    {
        feet = int(a);
        inch = (a-feet)*12;
    }
    void Display()
    { cout<<feet<<"\' - "<<inch<<"\""<<endl; }
};

int main()
{
    Distance d1;
    float a=11.19F ;
    d1 = a;
    d1.Display();

    return 0;
}
