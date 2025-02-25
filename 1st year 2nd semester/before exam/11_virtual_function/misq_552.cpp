// misq.cpp
// member square() function for Distance

#include <iostream>
using namespace std;

class Distance
{
private :
    int feet ;
    float inch;
public:
    Distance():feet(0),inch(0.0) { }
    Distance(int ft, float in):feet(ft),inch(in) { }
    void Display()
    { cout<<feet<<"\' - "<<inch<<"\""<<endl;}
    float square()
    {
        float ft = feet+(inch/12);
        return ft*ft;
    }
    friend float Square(Distance d)
    {
        float f = d.feet+(d.inch/12);
        return f*f;
    }
};

int main()
{
    Distance d(3, 6.0);
    d.Display();

    cout<<d.square()<<endl;;
    d.Display();

    cout<<Square(d)<<endl;;
    d.Display();

    return 0;
}
