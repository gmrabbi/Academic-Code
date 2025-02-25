#include <bits/stdc++.h>

using namespace std;

class Parallelogram
{
public:
    //Parallelogram() {}
    virtual void a()=0;
    //{ cout<<"Parallelogram."<<endl; }
};

class Rectangle: virtual public Parallelogram
{
public:
    Rectangle() { }
    void a()
    { cout<<"Rectangle."<<endl; }
};

class Rhombus:virtual public Parallelogram
{
public:
    Rhombus() { }
    void a()
    { cout<<"Rhombus."<<endl; }
};

class Square: public Rectangle , public Rhombus
{
public:
    Square() { }
    void a()
    { cout<<"Square."<<endl; }

};


int main()
{
    Parallelogram *s;
    Rhombus Rh;
    Rectangle Re;
    Square Sq;
    s = &Re ;
    s -> a();
    //s.a();
    //s.b();
    //s.c();
    //s.d();

    return 0;
}
