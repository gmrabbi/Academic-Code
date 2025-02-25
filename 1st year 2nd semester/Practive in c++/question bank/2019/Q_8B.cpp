#include <bits/stdc++.h>
using namespace std;

int sum(int a, int b)
{ return a+b ;}

float sum(float a, float b)
{ return a+b ;}

class Animal
{
public:
    virtual void Display();
};

class Cat : public Animal
{
public:
    void Display()
    {  cout<<"Cat"<<endl;  }
};

class Dog : public Animal
{
public:
    void Display()
    {  cout<<"Dog"<<endl;  }
};

int main()
{
    int a=2, b=3;
    float x=2.3 , y = 4.3;
    cout<<"Int sum : "<<sum(a,b)<<endl;
    cout<<"Float sum : "<<sum(x, y)<<endl;

    Animal *An;
    Cat ca;
    Dog dg;

    An = &ca;
    An->Display();

    An = &dg;
    An->Display();

    return 0;
}
