#include <bits/stdc++.h>
using namespace std;
/*
// function overloading;;
int sum(int a , int b)
{ return (a+b); }

float sum(float a , float b)
{ return (a+b); }

int main()
{
    int a=10, b=2;
    cout<<sum(a, b)<<endl;

    float x=13.2, y=2.2;
    cout<<sum(x, y)<<endl;

    return 0;
}*/

//Function overriding

class Animal
{
public:
    virtual void Display() = 0;
    /*{
        cout<<"Animal"<<endl;
    }*/
};

class Dog : public Animal
{
public:
    void Display()
    {
        cout<<"Dog"<<endl;
    }
};

class Cat:public Animal
{
public:
    void Display()
    {
        cout<<"Cat"<<endl;
    }
};


int main()
{
    Animal *A[2];
    Dog D;
    Cat C;
    A[0] = &D;
    A[1] = &C;

    A[0] -> Display();
    A[1] -> Display();

}
