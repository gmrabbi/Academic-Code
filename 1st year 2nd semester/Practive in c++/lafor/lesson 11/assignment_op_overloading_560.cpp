#include <bits/stdc++.h>
using namespace std;

class Distance
{
private:
    int feet ;
    float inch;
public:
    Distance(int f=0 , float i=0.0):feet(f), inch(i) { }
    void getFtInc(int &f , float &i)
    {
        f = feet ;
        i = inch;
    }
    Distance operator=(Distance); //obj = obj
};

//obj = obj=====================
Distance Distance::operator=(Distance d1)
{
    inch = d1.inch;
    feet = d1.feet;
    return *this;
}
int main()
{
    int x ; float y;
    Distance d1(2 , 3.4);
    d1.getFtInc(x , y);
    cout<<x<<"\' - "<<y<<"\""<<endl;
    Distance d2 = d1;
    d2.getFtInc(x , y);
    cout<<x<<"\' - "<<y<<"\""<<endl;

    return 0;
}
