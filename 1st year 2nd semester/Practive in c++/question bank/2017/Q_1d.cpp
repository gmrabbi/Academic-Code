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
};

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


int main()
{
    Time t1(2, 5, 7),t2(5, 57, 55), t3;
    t3.Final(t1, t2);
    //t1.Display();
    //t2.Display();
    t3.Display();

    return 0;
}
