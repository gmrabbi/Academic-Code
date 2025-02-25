// class to class conversation

#include <bits/stdc++.h>
using namespace std;

class Time
{
public:
    int hour;
    int mint;

    Time(int h= 0 , int m = 0):hour(h), mint(m) { }
    void getData()
    {
        cout<<"Enter hour : "; cin>>hour;
        cout<<"Enter min : "; cin>>mint;
    }
    void Display()
    {
        cout<<hour<<":"<<mint<<endl;
    }
};

class Minute
{
private:
    int mn;
    int hr;
public:
    Minute(Time t)
    {
        hr = t.hour;
        mn = t.mint;
    }
    void Display()
    {
        cout<<hr<<":"<<mn<<endl;
    }

};


int main()
{
    Time t1;
    //Minute m1;
    cout<<"Initialization point .."<<endl;
    cout<<"T1 : "; t1.Display();
    //cout<<"M1 : "; m1.Display();

    cout<<endl;

    t1.getData();
    Minute m1 = t1;
    cout<<"Assinging the value "<<endl;
    cout<<"T1 : "; t1.Display();
    cout<<"M1 : "; m1.Display();


}
