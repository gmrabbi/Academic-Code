#include <iostream>

using namespace std;

class A
{
public:
    int sum(int a, int b) { return a+b; }
    float sum(float a, float b) { return a+b; }
    void show() { cout<<" A "<<endl; }
};

class B : public A
{
public:
    void show() { cout<<" B "<<endl; }
};

int main()
{
    B bb;
    cout<<"Float : "<<bb.sum(2.6F , 4.5F)<<endl;
    cout<<"Int : "<<bb.sum(2 , 5)<<endl;

    bb.A::show();
    bb.B::show();

    return 0;
}
