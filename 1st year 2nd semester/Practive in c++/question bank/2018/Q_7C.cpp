#include <bits/stdc++.h>

using namespace std;

class Time
{
    int hours;
    int minutes;
public:
    Time() :hours(0), minutes(0) { };
    Time(int h, int m):hours(h), minutes(m) { }
    Time operator++(); //prefix
    Time operator++(int); //postfix
    void Display()
    {
        cout<<hours<<":"<<minutes<<endl;
    }
};

Time Time::operator++()
{
    ++hours;
    ++minutes;
    if(hours>= 24)
    {
        hours -= 24;
    }
    if(minutes >= 60)
    {
        minutes-=60;
        hours++;
    }
    return *this;
}

Time Time::operator++(int)
{
    hours++;
    minutes++;
    if(hours>= 24)
    {
        hours -= 24;
    }
    if(minutes >= 60)
    {
        minutes-=60;
        hours++;
    }
    return *this;
}

int main()
{
    Time t1(22, 58);
    t1.Display();

    Time t2 = ++t1;
    t1.Display();
    t2.Display();

    Time t3 = t2++;
    t2.Display();
    t3.Display();

    return 0;
}

