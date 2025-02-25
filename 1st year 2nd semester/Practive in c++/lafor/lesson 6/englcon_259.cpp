#include <bits/stdc++.h>

using namespace std;

class Distance
{
private :
    int feet;
    float inch;
public:
    Distance():feet(0), inch(0.0)
        {  cout<<"with out para"<<endl; };

    Distance(int ft , float inc):inch(inc), feet(ft)
        {  cout<<"with para"<<endl; };
    void getDistance()
    {
        cout<<"Enter feet : "; cin>>feet;
        cout<<"Enter inch : "; cin>>inch;
    }
    void showData()
    {
        cout<<feet <<"\' - "<<inch<<"\""<<endl;
    }
    void addDistance(Distance , Distance);
    ~Distance()
    { cout<<"Distractor called."<<endl;}
};

void Distance::addDistance(Distance d1 ,Distance d2)
{
    feet = 0;
    inch = d1.inch + d2.inch;
    if(inch >= 12.0 )
    {
        feet += 1;
        inch -= 12;
    }
    feet += d1.feet + d2.feet;
}

int main()
{
    ////////////copy constractor  idea;==================
    Distance d1(11 , 6.25) ;
    Distance d2(d1);
    Distance d3 = d1;

    d1.showData();
    d2.showData();
    d3.showData();
    return 0;
}
