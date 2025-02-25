#include <bits/stdc++.h>
using namespace std;

class Time
{
private:
    int hour ;
    int mint ;
    int sec;

public:
    Time(): hour(0), mint(0), sec(0) { }
    Time(int h , int m , int s): hour(h), mint(m), sec(s) { }

    /*Time addTime( Time t)
    {
        hour += t.hour;
        mint += t.mint;
        sec += t.sec;
        if(sec>= 60)
        {
            mint++;
            sec -= 60;
        }
        if(mint>=60)
        {
            hour++;
            mint -= 60;
        }
        return Time(hour , mint , sec);
    }*/
    Time operator + (Time);
    Time operator ++ ();
    Time operator ++ (int);
    bool operator == (Time);
    bool operator <= (Time);

    void Display()
    {
        cout<<hour<<":"<<mint<<":"<<sec<<endl;
    }
};

Time Time::operator+(Time t)
{
        hour += t.hour;
        mint += t.mint;
        sec += t.sec;
        if(sec>= 60)
        {
            mint++;
            sec -= 60;
        }
        if(mint>=60)
        {
            hour++;
            mint -= 60;
        }
        return Time(hour , mint , sec);
}

Time Time::operator++()
{
    ++hour;
    ++mint;
    ++sec;
    if(sec >= 60)
    {
        mint++;
        sec -= 60;
    }
    if(mint >= 60)
    {
        hour++;
        mint -= 60;
    }
    return Time(hour , mint, sec);
}
Time Time::operator++(int)
{
    hour++;
    mint++;
    sec++;
    if(sec >= 60)
    {
        mint++;
        sec -= 60;
    }
    if(mint >= 60)
    {
        hour++;
        mint -= 60;
    }
    return Time(hour , mint, sec);
}

bool Time::operator==(Time t)
{
    return ((t.hour == hour)&& (t.mint == mint) &&(t.sec == sec))?true:false;
}

bool Time::operator<=(Time t)
{
    return ((t.hour <= hour) && (t.mint<=mint) && (t.sec<=sec))?true:false;
}

int main()
{
    Time t1(11, 23, 21), t2(3, 45, 54), t3;
    //t1.addTime(t2);
    cout<<"t1 obj : "; t1.Display();
    t1++;
    cout<<"t1 obj t1++ : "; t1.Display();

    t3 = t1 + t2;
    cout<<"t3 = t1+t2 obj : "; t3.Display();
    ++t3;
    cout<<"++t3 obj : "; t3.Display();
    cout<<endl;

    cout<<"t1 obj : "; t1.Display();
    cout<<"t3 obj : "; t3.Display();

    //t1 = t3;
    if(t1 == t3)
        cout<<"t1 equal to t3"<<endl;
    else
        cout<<"t1 not equal to t3"<<endl;

    if(t1<= t3)
        cout<<"t1 is less than or equal to t3"<<endl;
    else
        cout<<"t1 is gather than t3"<<endl;



}










