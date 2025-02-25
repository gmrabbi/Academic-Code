#include <iostream>

using namespace std;

class Time
{
private:
    int hours;
    int minutes;
    int seconds;
public:
    Time():hours(0), minutes(0), seconds(0) { }
    Time(int h, int m, int s):hours(h), minutes(m), seconds(s) { }
    void Display()
    { cout<<hours<<":"<<minutes<<":"<<seconds<<endl; }
    Time addTime(Time t)
    {
        Time t;
        t.hours = t1.hours + t2.hours;
        t.minutes = t1.minutes + t2.minutes;
        t.seconds = t1.seconds + t2.seconds;
        if(t.seconds>=60)
        {
            t.seconds -= 60;
            t.minutes++;
        }
        if(t.minutes >=60)
        {
            t.minutes -= 60;
            t.hours++;
        }
        return t;
    }
};

int main()
{
    Time t1(23, 34, 54), t2(12, 43, 12), t3;
    t1.Display();
    t2.Display();
    t3.Display();

    t3 = t3.addTime(t1, t2);
    t1.Display();
    t2.Display();
    t3.Display();

    return 0;
}
