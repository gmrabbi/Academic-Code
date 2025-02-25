#include <bits/stdc++.h>

using namespace std;

struct Distance
{
    int feet ;
    float inch;
};

Distance addDist(Distance d1 , Distance d2)
{
    Distance d3;
    d3.feet = d1.feet + d2.feet;
    d3.inch = d1.inch + d2.inch;

    if(d3.inch >= 12.0)
    {
        d3.feet++;
        d3.inch -= 12.0;
    }
    return d3;
}

void Display(Distance d)
{
    cout<<d.feet<<"\' - "<<d.inch<<"\"";
}

int main()
{
    Distance d1 , d2, d3;

    cin>>d1.feet;
    cin>>d1.inch;

    cin>>d2.feet;
    cin>>d2.inch;

    d3 = addDist(d1,d2);

    Display(d1); cout<<" + "; Display(d2); cout<<"="; Display(d3);

}
