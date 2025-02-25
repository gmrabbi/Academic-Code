#include <iostream>

using namespace std;

class Distance
{
private:
    int feet;
    float inch;
public:
    Distance(int ft, float inc):feet(ft), inch(inc)
    {  cout<<"It's Constructor."<<endl;  }

    ~Distance()
    {  cout<<"It's Distractor."<<endl; }

    void Display()
    {
        cout<<feet<<"\' - "<<inch<<"\""<<endl;
    }
};

int main()
{
    Distance d1(11, 2.3F);
    Distance d2(d1);
    Distance d3 = d1;

    d1.Display();
    d2.Display();
    d3.Display();

    return 0;
}
