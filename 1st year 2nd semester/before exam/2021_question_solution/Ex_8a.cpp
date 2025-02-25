#include <iostream>

using namespace std;

int sum(int a , int b)
{ return a+b; }

float sum(float a, float b)
{ return a+b; }

class Dog
{
public:
    virtual void sound()
    {  cout<<"Dog sound.."<<endl; }
};
class Cat: public Dog
{
public:
    void sound()
    {  cout<<"Cat sound.."<<endl;  }
};

int main()
{
    int a= 5 , b = 9;
    cout<<sum(a,b)<<endl;
    float x= 5.6, y = 8.9;
    cout<<sum(x, y)<<endl;

    Dog *dd;
    Cat cc;
    dd = &cc;
    dd ->sound();
//    cc.dd::sound();
    cc.sound();

    return 0;
}
