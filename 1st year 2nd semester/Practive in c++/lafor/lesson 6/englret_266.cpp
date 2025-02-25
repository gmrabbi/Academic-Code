#include <bits/stdc++.h>

using namespace std;

class Distance
{
private:
    int feet ;
    float inch;
public:
    Distance():feet(0), inch(0.0)
        {   }
    Distance(int ft , float inc):feet(ft), inch(inc)
        {   }
    void getData()
    {
        cout<<"Enter feet : "; cin>>feet;
        cout<<"Enter inch : "; cin>>inch;
    }
    void showData()
    {
        cout<<feet<<"\' - "<<inch<<"\""<<endl;
    }
    Distance addDistance(Distance);
};

Distance Distance::addDistance(Distance d1)
{
    Distance temp;
    temp.inch += inch + d1.inch;
    if(temp.inch > 12.0)
    {
        temp.inch -= 12.0;
        temp.feet++;
    }
    temp.feet += feet +  d1.feet;
    cout<<temp.feet<<"\' - "<<temp.inch<<"\""<<endl;
    //return temp;
}

int main()
{
    Distance d1 , d3;
    Distance d2(11 , 6.25);

    d1.getData();
    d3 = d1.addDistance(d2);

    d1.showData();
    d2.showData();
    //d3.showData();
    return 0;
}
