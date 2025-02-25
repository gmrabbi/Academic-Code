//#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
struct Distance
{
    int feet;
    float inch;
};

void show(struct Distance d1 , struct Distance d2)
{
    /*
    cout<<("%d ",d.feet);
    cout<<("\' - ");
    cout<<("%.3f ",d.inch);
    cout<<("\"\n");
    */
    int feet = d1.feet + d2.feet;
    float inch = d1.inch + d2.inch;
    if(inch > 12.0)
    {
        inch -= 12.0;
        feet++;
    }
    cout<<feet<<"\' - "<<inch<<"\""<<endl;
}

int main()
{
    struct Distance d1 ,d2;
    cout<<("Distance 1\n");
    cout<<("Enter feet : "); cin>>(d1.feet);
    cout<<("Enter inch : "); cin>>(d1.inch);

    cout<<("\nDistance 2\n");
    cout<<("Enter feet : "); cin>>(d2.feet);
    cout<<("Enter inch : "); cin>>(d2.inch);

    show(d1 , d2);
    //show(d2);


    return 0;
}
