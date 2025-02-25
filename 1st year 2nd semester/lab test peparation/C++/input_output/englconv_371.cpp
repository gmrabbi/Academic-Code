#include <bits/stdc++.h>

using namespace std;

class Distance
{
private:
    int feet ;
    float inch;
    float MTF;
public:
    Distance(int ft = 0 , float in=0.0): feet(ft), inch(in), MTF(3.280839F) { }
    Distance(float m) : MTF(3.280839F)
    {
        float fra_cal = m*MTF;
        feet = int(fra_cal);
        inch = 12*(fra_cal - feet);
    }
    operator float()
    {
        return ((inch/12)+feet)/MTF;
    }
    void Display()
    {
        cout<<feet<<"' - "<<inch<<"\""<<endl;
    }

};

int main()
{
    Distance d1 = 3.54F;
    d1.Display();

    Distance d2(5, 6.88687);
    float meter ;
    meter = d2;
    cout<<meter<<endl;
    return 0;
}
