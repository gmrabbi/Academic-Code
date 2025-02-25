#include <bits/stdc++.h>

using namespace std;

class Distance
{
private:
    int feet;
    float inch;
public:
    Distance(int ft=0 , float in=0): feet(ft),inch(in) { }
    void setDistance()
    {
        cout<<"Enter feet : "; cin>>feet;
        cout<<"Enter inch : "; cin>>inch;
    }
    void Display()
    {
        cout<<feet<<"\' - "<<inch<<"\""<<endl;
    }
};

int main()
{
    Distance d1;
    d1.setDistance();
    d1.Display();
    cout << endl;

    Distance* d2;
    d2  = new Distance;
    d2 ->setDistance();
    d2 ->Display();
    cout << endl;

    Distance& dist = *(new Distance); // create Distance object
    // alias is “dist”
    dist.setDistance(); // access object members
    dist.Display(); // with dot operator
    cout << endl;

    return 0;
}
