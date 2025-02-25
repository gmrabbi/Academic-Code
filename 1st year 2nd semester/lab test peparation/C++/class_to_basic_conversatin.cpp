// class to basic conversation
#include <bits/stdc++.h>
using namespace std;

class Time
{
private:
    int hour;
    int mint;
public:
    Time(int h = 0 , int m=0):hour(h), mint(m) { }
    void getData()
    {
        cout<<"Enter hour : " ; cin>>hour;
        cout<<"Enter mint : " ; cin>>mint;
    }
    void Display()
    {
        cout<<hour<<":"<<mint<<endl;
    }
    operator int ()
    {
        return hour*60 + mint;
    }

};

int main()
{
    Time t1;
    int x;
    t1.getData();
    t1.Display();
    x = t1;
    cout<<x;

    return 0;
}
