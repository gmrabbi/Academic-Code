#include <bits/stdc++.h>

using namespace std;

class Distance
{
private :
    int feet;
    float inch;
public:
    Distance(int ft=0 , float in=0.0): feet(ft) , inch(in){ }

    void Display()
    {
        cout<<feet <<"\' - "<<inch<<"\""<<endl;
    }
    void get_Data()
    {
        cout<<"Enter feet (int): "; cin>>feet;
        cout<<"Enter inch (float): "; cin>>inch;
    }
    Distance operator + (Distance d1) const
    {
        int nu = abs(inch +  d1.inch);
        float ft = abs(feet +  d1.feet);
        if(nu >= 12.0)
        {
            nu -= 12;
            ft++;
        }
        return Distance(nu , ft);
    }
};


int main()
{
    Distance d1(6, 6.25), d2 , d3;
    d2.get_Data();

    d3 = d1 + d2;

    d1.Display();
    d2.Display();
    d3.Display();


    return 0;
}
