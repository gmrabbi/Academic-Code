#include <iostream>

using namespace std;

class Time
{
private:
    int hours, minutes , seconds;
public:
    Time():hours(0),minutes(0),seconds(0) { }
    Time(int h, int m, int s):hours(h),minutes(m),seconds(s) { }
    void Display()
    { cout<<hours<<":"<<minutes<<":"<<seconds<<endl; }

    Time(Time& t)
    {
        hours = t.hours;
        minutes = t.minutes;
        seconds = t.seconds;
        cout<<"cp constructor ()"<<endl;
    }
    Time operator=(Time t)
    {
        hours = t.hours;
        minutes = t.minutes;
        seconds = t.seconds;
        cout<<"cp constructor = "<<endl;
    }
};

int main()
{

    Time T2(2, 3, 45), T1;
    //Time T2(T1);
    T1 = T2;


    return 0;
}
