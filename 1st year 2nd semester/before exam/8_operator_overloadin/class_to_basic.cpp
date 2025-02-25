#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Distance
{
private:
    int feet;
    float inch;
public:
    Distance():feet(0), inch(0.0) { }
    Distance(int ft, float in):feet(ft), inch(in) { }
    void Display()
    {
        cout<<feet<<"\' - "<<inch<<"\""<<endl;
    }
    operator float()
    { return feet+(inch/12);  }
};

int main()
{
    Distance d1(11, 8.9);
    d1.Display();
    float a1;
    a1 = d1;
    cout<< a1 <<endl;
    return 0;
}
