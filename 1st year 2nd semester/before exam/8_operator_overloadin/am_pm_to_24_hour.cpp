#include <iostream>

using namespace std;

class Time
{
private:
    int hour;
    int Min;
    string s ;
public:
    Time():hour(0), Min(0),s("am") { }
    Time(int h, int m , string s):hour(h),Min(m), s(s)
    {
        if(s == "am" && hour >=12)
        {
            hour-=12;
        }

    }


};

int main()
{
    int hr , mn;
    string iam;
    cin>>hr>>mn;
    cin>>iam;

    Time t1(hr, mn, iam);


    return 0;
}
