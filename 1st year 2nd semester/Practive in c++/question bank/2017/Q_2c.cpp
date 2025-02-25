#include <bits/stdc++.h>
using namespace std;

class Time
{
private:
    int hours, minutes , seconds;
public:
    Time():hours(0), minutes(0), seconds(0) { }
    Time(int h, int m, int s):hours(h), minutes(m), seconds(s) { }

    void Display()
    {
        cout<<hours<<":"<<minutes<<":"<<seconds<<endl;
    }
    Time Final(Time , Time);
    Time operator+(Time); // a = b+c;
    Time operator++(); // ++a
    Time operator++(int); // a++
    bool operator==(Time);
    bool operator>(Time);
};
// adding two time obj
Time Time::Final(Time t1 , Time t2)
{
    //Time t;
    hours = t1.hours + t2.hours;
    minutes = t1.minutes + t2.minutes;
    seconds = t1.seconds + t2.seconds;
    if(seconds >= 60)
    {
        minutes++;
        seconds -= 60;
    }
    if(minutes >= 60)
    {
        hours++;
        minutes -= 60;
    }
    return Time(hours, minutes, seconds);
}

//overloading + operator.
Time Time::operator+(Time t1)
{
    Time  t;
    t.hours = hours + t1.hours;
    t.minutes = minutes + t1.minutes;
    t.seconds = seconds + t1.seconds;
    if(t.seconds >= 60)
    {
        t.minutes++;
        t.seconds -= 60;
    }
    if(t.minutes >=60)
    {
        t.hours++;
        t.minutes -= 60;
    }
    return t;
}

Time Time::operator++()
{
    ++hours;
    ++minutes;
    ++seconds;
    return *this;
}

Time Time::operator++(int)
{
    hours++;
    minutes++;
    seconds++;
    return *this;
}

bool Time::operator==(Time t1)
{
    long s1 = ((hours*3600)+(minutes*60)+seconds);
    long s2 = ((t1.hours*3600)+(t1.minutes*60)+t1.seconds);
    return ((s1==s2)?true:false);
}

bool Time::operator>(Time t1)
{
    long s1 = ((hours*3600)+(minutes*60)+seconds);
    long s2 = ((t1.hours*3600)+(t1.minutes*60)+t1.seconds);
    return ((s1>s2)?true:false);
}

int main()
{
    Time t1(2, 5, 7),t2(5, 57, 55), t3;
    //t3.Final(t1, t2);
    //t1.Display();
    //t2.Display();
    t3.Display();

    //t3 = t1 + t2;
    t1 = t2;
    if (t2==t1)
        cout<<"t1 grather then t2"<<endl;
    else
        cout<<"t1 less then t2."<<endl;


    t3.Display();


    return 0;
}
