#include <bits/stdc++.h>
using namespace std;

class Distance
{
private:
    int Data;
public:
    Distance(){ }
    Distance(int d):Data(d) { }

    Distance(Distance& d)
    {
        Data = d.Data;
    }
    void Display()
    {
        cout<<Data<<endl;
    }
    void operator = (Distance);
};

void Distance::operator=(Distance d)
{
    Data = d.Data;
    //return Distance(Data);
}

int main()
{
    Distance d1(37);
    Distance d2;

    d2 = d1;
    cout<<"\nd2 : "; d2.Display();

    Distance d3(d1);
    cout<<"\nd3 = "; d3.Display();
    cout<<endl;
    return 0;

}
