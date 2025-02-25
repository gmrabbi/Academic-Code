#include <bits/stdc++.h>
using namespace std;

class Time
{
private :
    int hour;
    int mint;
    int sec;
public :
    Time(int h = 0, int m = 0 , int s = 0 ): hour(h), mint(m), sec(s) {  }
    void setTime()
    {
        cout<<"Enter the value for hour : "; cin>>hour;
        cout<<"Enter the value for min : "; cin>>mint;
        cout<<"Enter the value for sec : "; cin>>sec;
    }
    void Display()
    {
        cout<<hour<<":"<<mint<<":"<<sec<<endl;
    }
    Time operator ++();
    Time operator ++(int);
    bool operator >(Time);
};

Time Time::operator++()
{
     return Time(++hour, ++mint, ++sec );
}

Time Time::operator++(int)
{
    return Time(hour++, mint++, sec++ );
}

bool Time::operator > (Time t)
{
    return ((t.hour>hour)&&(t.mint>mint)&&(t.sec>sec))?true:false;
}

int main()
{
    Time t1(4) , t2(5);
    t1++;
    t1.Display();

    ++t2;
    t2.Display();

    if(t1>t2)
        cout<<"t1 is larger t2."<<endl;
    else
        cout<<"t1 is not larger then t2"<<endl;

}
