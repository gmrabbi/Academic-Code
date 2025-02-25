#include <bits/stdc++.h>

using namespace std;

class Distance
{
private :
    int feet;
    float inch;
public:
    Distance(int ft = 0 , float in = 0.0): feet(ft), inch(in) { }
    void get_Data()
    {
        cout<<"Enter inch : "; cin>>inch;
        cout<<"Enter feet : "; cin>>feet;
    }

    void Display()
    {  cout<<feet<<"\' - "<<inch<<"\""<<endl;  }

    bool operator == (Distance d1) const
    {
        int a = feet + inch/12;
        int b = d1.feet + d1.inch/12;
        return (a==b)? true : false ;
    }

};

int main()
{
    Distance d1, d2(6, 2.5);
    d1.get_Data();

    d1.Display();
    d2.Display();
    if(d1 == d2)
        cout<<"d2 is Equal"<<endl;
    else
        cout<<"d1 is not equal"<<endl;
}
