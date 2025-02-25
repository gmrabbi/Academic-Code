#include <bits/stdc++.h>

using namespace std;


class Distance
{
private:
    int feet;
    float inch;
public:
    Distance():feet(0), inch(0.0) { }
    Distance(int f, float in):feet(f), inch(in) { }

    friend Distance operator*(Distance, int);
    void Display() {cout<<feet<<"\'- "<<inch<<"\""<<endl;}
};

Distance operator*(Distance d1, int a)
{
    int feet = d1.feet*a;
    float inch = d1.inch*a;
    do{
        if(inch>12.0)
        {
            inch-=12.0;
            feet++;
        }
    }while(inch>12.0);
    return Distance(feet , inch);
}


int main()
{
    Distance d1(12, 10.3), d2(2, 3.2);
    d1.Display();
    d2.Display();

    d2 = d1 * 3;
    d1.Display();
    d2.Display();


    return 0;
}
