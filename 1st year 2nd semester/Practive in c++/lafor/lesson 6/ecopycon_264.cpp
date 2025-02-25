//copy constructor..
#include <bits/stdc++.h>

using namespace std;

class Distance
{
private :
    int feet;
    float inch;
public:
    //Distance() : feet(0), inch(0.0) { }
    Distance(int f=0, float in=0.0):feet(f), inch(in) { }
    void getdist()
    {
        cout<<"\nEnter feet: "; cin>>feet;
        cout<<"Enter inch: "; cin>>inch;
    }
    void showdist()
    {  cout<<feet<<"\' - " <<inch<<"\""<<endl; }
};

int main()
{
    Distance dist1(11, 6.25);
    Distance dist2(dist1);
    Distance dist3 = dist1;

    cout<<"\ndist1 = "; dist1.showdist();
    cout<<"\ndist2 = "; dist2.showdist();
    cout<<"\ndist3 = "; dist3.showdist();
    cout<<endl;

    return 0;
}
