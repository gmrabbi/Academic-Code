#include <bits/stdc++.h>
using namespace std;

class Time
{
private:
    int hour;
    int mint;
    int sec;
public:
    Time():hour(0), mint(0), sec(0) { }
    Time(int h, int m, int s):hour(h), mint(m), sec(s) { }
    void display()
    { cout<<hour<<":"<<mint<<":"<<sec<<endl; }
    Time operator +( Time t ) //const
    {
        Time temp;
        temp.hour = t.hour + hour;
        temp.mint = t.mint + mint;
        temp.sec = t.sec + sec;
        if(temp.sec >= 60)
        {
            temp.mint++;
            temp.sec -= 60;
        }
        if(temp.mint>=60)
        {
            temp.hour++;
            temp.mint-=60;
        }
        return temp;
    }
};

int main()
{
    Time t1(2, 4 , 48), t2(8, 58, 23) , t3;

    t1.display();
    t2.display();
    t3.display();

    t3 = t1 + t2;
    t3.display();
    cout<<"------------"<<endl;
    t1.display();
    t2.display();
    t3.display();
    return 0;
}
