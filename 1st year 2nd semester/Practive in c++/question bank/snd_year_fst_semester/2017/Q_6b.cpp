#include <iostream>
#define pi 3.1416

using namespace std;

class shape
{
protected:
    double x;
    double y;
public:
    void get_data()
    {
        cout<<"X : "; cin>>x;
        cout<<"Y : "; cin>>y;
        cout<<"calling.."<<endl;
    }
    virtual void display_area() = 0;
};

class triangle : public shape
{
public:
    void display_area()
    { cout<<"Area of triangle = "<<(0.5*x*y)<<endl; }
};

class rectangle : public shape
{
public:
    void display_area()
    { cout<<"Area of rectangle = "<<(x*y)<<endl; }
};

class circle:public shape
{
public:
    void display_area()
    { cout<<"Area of circle = "<<(pi*x*x)<<endl; }
};

int main()
{
    shape *sp;
    triangle tr;
    rectangle rc;
    circle cr;

    sp->get_data();

    sp = &tr;
    sp ->display_area();

    sp = &rc;
    sp ->display_area();

    sp = &cr;
    sp ->display_area();
}
