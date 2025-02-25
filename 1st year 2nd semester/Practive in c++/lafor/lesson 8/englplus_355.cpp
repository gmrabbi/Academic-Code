#include <bits/stdc++.h>

using namespace std;

class Distance
{
private :
    int feet;
    float inch;
public:
    Distance(int ft=0 , float inch=0.0): feet(ft), inch(inch)
    {   }
    void PutData()
    {
        cout<<"Enter inch : "; cin>>inch;
        cout<<"Enter feet : "; cin>>feet;
    }
    void ShowData()
    {
        cout<<feet<<"\' -"<<inch<<"\""<<endl;
    }
    Distance operator + (Distance) ;
};

Distance Distance::operator+(Distance d1)
{
    int f = feet + d1.feet;
    float in = inch + d1.inch;
    if(in >= 12.0)
    {
        in -= 12.0;
        f++;
    }
    return Distance(f , in);
}

int main()
{
    Distance d1 , d2(11, 6.25);
    Distance d3, d4;

    d1.PutData();

    d3 = d1 + d2;
    d4 = d1 + d2 + d3 +d4;
    d1.ShowData();
    d2.ShowData();
    d3.ShowData();
    d4.ShowData();
    return 0;
}
