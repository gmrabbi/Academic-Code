#include <bits/stdc++.h>

using namespace std;

class Distance
{
private :
    int feet;
    float inch;
public:
    Distance():feet(0), inch(0.0)
    {   };
    Distance(int feet , float inch):feet(feet), inch(inch)
    {    };
    void getData()
    {
        cout<<"Enter Feet : "; cin>>feet;
        cout<<"Enter inch : "; cin>>inch;
    }
    void showData()
    {
        cout<<inch<<"\' - "<<feet<<"\""<<endl;
    }
    Distance addDistance(const Distance& ) const;
};

Distance Distance::addDistance(const Distance& d1) const
{
    Distance temp;
    temp.inch = inch + d1.inch;
    if(temp.inch >= 12.0)
    {
        temp.inch -= 12.0;
        temp.feet = 1;
    }
    temp.feet += feet + d1.feet;
    return temp;
}

int main()
{
    Distance dist2 , dist3;
    Distance dist1(11, 6.25);

    dist2.getData();
    dist3 = dist1.addDistance(dist2);

    dist1.showData();
    dist2.showData();
    dist3.showData();

    return 0;
}
