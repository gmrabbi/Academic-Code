#include <bits/stdc++.h>

using namespace std;

struct Distacne
{
    int feet;
    float inch;
};

void Display(Distacne d)
{
    cout<<d.feet<<"\' - "<<d.inch<<"\""<<endl;
}

int main()
{
    Distacne d1 , d2;
    cin>>d1.feet;
    cin>>d1.inch;

    cin>>d2.feet;
    cin>>d2.inch;

    Display(d1);
    Display(d2);

    cout<<"End"<<endl;
    return 0 ;
}
