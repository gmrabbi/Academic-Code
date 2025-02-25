#include <iostream>

using namespace std;

class Time
{
private:
    int hours;
    int minutes;
    int seconds;
public:
    Time()
    {
        hours = 0;
        minutes =0;
        seconds = 0;
    }
    Time(int h, int m , int s)
    {
        hours = h;
        minutes = m;
        seconds = s;
    }
    void Display()
    {  cout<<hours<<":"<<minutes<<":"<<seconds<<endl;  }
    Time operator+(Time); //t3 = t1+ t2
    Time operator++(); //prefix ++t;
    Time operator++(int);
};
Time Time::operator+(Time t1)
{
    //Time t;
    hours = hours + t1.hours;
    minutes = minutes + t1.minutes;
    seconds = seconds + t1.seconds;
    if(seconds >= 60)
    {
        seconds -= 60;
        minutes++;
    }
    if(minutes >= 60)
    {
       minutes -= 60;
       hours++;
    }
    return *this;
}
Time Time::operator++()
{
    ++hours;
    ++minutes;
    ++seconds;
    if(seconds >= 60)
    {
        seconds -= 60;
        minutes++;
    }
    if(minutes >= 60)
    {
       minutes -= 60;
       hours++;
    }
    return *this;
}

Time Time::operator++(int)
{
    hours++;
    minutes++;
    seconds++;
    if(seconds >= 60)
    {
        seconds -= 60;
        minutes++;
    }
    if(minutes >= 60)
    {
       minutes -= 60;
       hours++;
    }
    return *this;
}

int main()
{
    Time t1(12, 23, 45), t2(34, 59, 23), t3;
    t1.Display();
    t2.Display();
    t3.Display();
    cout<<endl;

    t3 = t1 + t2;
    t1.Display();
    t2.Display();
    t3.Display();

    cout<<endl;
    t2++;
    t2.Display();

    return 0;
}
