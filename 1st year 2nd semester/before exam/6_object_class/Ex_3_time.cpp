#include <iostream>
using namespace std;

class Time
{
private:
    int hour;
    int mins;
    int sec;
public:
    Time():hour(0), mins(0), sec(0) { }
    Time(int h, int m, int s):hour(h), mins(m), sec(s) { }
    void Display()
    { cout<<hour<<":"<<mins<<":"<<sec<<endl; }
    void add_time(Time t1, Time t2)
    {
        sec = t1.sec + t2.sec;
        mins = t1.mins + t2.mins;
        hour = t1.hour + t2.hour;
        if(sec>59)
        {  sec=60; mins++; }
        if(mins>59)
        {  mins-=60; hour++; }
        //return Time(h , m , s);
    }
};

int main()
{
    Time t1(2, 57, 23), t2(3, 34, 57), t3;
    t1.Display();
    t2.Display();
    t3.add_time(t1 , t2);
    t3.Display();

    return 0;
}
