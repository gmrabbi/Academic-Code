// Basic Data type to Class conversation

#include <bits/stdc++.h>

using namespace std;

class Time
{
private:
    int mint;
    int hour;
public:
    Time(int n=0):hour(n%3), mint(n%4) { }
    void getData()
    {
        cout<<"Enter hour : "; cin>>hour;
        cout<<"Enter min : "; cin>>mint;
    }
    void Display()
    {
        cout<<hour <<":"<<mint<<endl;
    }
};

int main()
{
    Time t1, t2;
    cout<<"At initialization point .."<<endl;
    cout<<"T1 : "; t1.Display();
    cout<<"T2 : ";t2.Display();

    t1.getData();
    t2 = 34;

    cout<<"After value assign .."<<endl;
    cout<<"T1 : "; t1.Display();
    cout<<"T2 : ";t2.Display();
}
