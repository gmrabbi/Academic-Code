#include <iostream>

using namespace std;

struct Distance
{
    int feet;
    float inch;
};

void larger(Distance a , Distance b)
{
    float d1 = a.feet+(a.inch/12);
    float d2 = b.feet+(b.inch/12);
    float m = d1>d2?d1:d2;
    cout<<"Large value is : "<<m<<endl;
}


int main()
{
    Distance d1 , d2;
    cout<<"First Distance : "<<endl;
    cout<<"Feet : "; cin>>d1.feet;
    cout<<"Inch : "; cin>>d1.inch;
    cout<<endl;

    cout<<"Second Distance : "<<endl;
    cout<<"Feet : "; cin>>d2.feet;
    cout<<"Inch : "; cin>>d2.inch;
    cout<<endl;

    larger(d1 , d2);


    return 0;
}
