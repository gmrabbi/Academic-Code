#include <bits/stdc++.h>
using namespace std;

class Distance
{
private:
    int feet;
    float inch;
public:
    class IEx { };
    Distance():feet(0), inch(0.0) {}
    Distance(int f, float in)
    {
        if(in>12.0)
            throw IEx();
        feet = f ;
        inch = in;
    }

    void getData()
    {
        cout<<"Enter feet : "; cin>>feet;
        cout<<"Enter inch : "; cin>>inch;
        if(inch>12.0)
            throw IEx();
    }

    void show()
    {
        cout<<feet<<"\' - "<<inch<<"\""<<endl;
    }
};


int main()
{
    try
    {
        Distance d1(17, 3.5);
        Distance d2;
        d2.getData();

        cout<<"Distance 1 : "; d1.show(); //<<endl;
        cout<<"Distance 2 : "; d2.show(); //<<endl;

    }
    catch(Distance::IEx)
    {
        cout<<"Inch can't >12.0"<<endl;exit(1);
    }
    cout<<"Normal Execution...."<<endl;
}
