#include <bits/stdc++.h>
using namespace std;

class Distance
{
private:
    int feet;
    float inch;
    const int MTF;
public:
    Distance(int f=0, float in=0.0):feet(f), inch(in), MTF(1250/381) { }
    Distance(float meter): MTF(1250/381)
    {
        float fracmeter = meter*MTF;
        feet = int(fracmeter);
        inch = 12*(fracmeter- feet);
    }
    void Display()
    {
        cout<<feet<<"\'-"<<inch<<"\""<<endl;
    }
    operator float() const
    {
        float fracfeet = inch/12;
        fracfeet += static_cast<float>(feet);
        return fracfeet/MTF;
    }
};


int main()
{
    float mtrs;
    Distance d1=2.35F;
    d1.Display();

    Distance d2(5, 10.25);
    mtrs = d2;
    cout<<mtrs<<endl;


    return 0;
}
