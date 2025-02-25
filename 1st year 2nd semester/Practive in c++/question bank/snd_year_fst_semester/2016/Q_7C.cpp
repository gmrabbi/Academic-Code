#include <iostream>

using namespace std;

class Polygon
{
protected:
    double x;
    double y;
public:
    void Set_Value()
    {
        cout<<"x : "; cin>>x;
        cout<<"y : "; cin>>y;
    }
    virtual void Area() = 0;
};

class Rectangle:public Polygon
{
public:
    void Area()
    {
        cout<<"Area of Rectangle : "<<x*y<<endl;
    }
};

class Triangle: public Polygon
{
public:
    void Area()
    {
        cout<<"Area of Triangle : "<<0.5*x*y<<endl;
    }
};

int main()
{
    Polygon *p;
    Rectangle re;
    Triangle tr;
    p-> Set_Value();


    p = &re;
    //p-> Set_Value();
    p->Area();

    p = &tr;
    //p-> Set_Value();
    p->Area();

    return 0;
}
