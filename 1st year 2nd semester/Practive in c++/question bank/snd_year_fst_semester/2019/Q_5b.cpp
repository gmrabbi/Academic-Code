#include <iostream>
using namespace std;

static int num = 0;
class Distance
{
private:
    int feet ;
    float inch;
public:
    //Distance():feet(0),inch(0.0) { }
    Distance(int f=0, float in=0.0):feet(f),inch(in) { num++; cout<<"Constructor "<<num<<endl;  }
    void Display()
    {  cout<<feet<<"\' - "<<inch<<"\""<<endl;  }
    void sum(Distance , Distance);
    Distance operator=(Distance d)
    {
        cout<<"\nCopy constructor calling..\n";
        feet = d.feet;
        inch = d.inch;
        return Distance(feet, inch);
    }
    ~Distance()
    { num--; cout<<"Distructor "<<num+1<<endl;  }
    //Distance operator
};

void Distance::sum(Distance d1, Distance d2)
{
    //Distance temp;
    feet = d1.feet  + d2.feet;
    inch = d1.inch + d2.inch;
    if(inch >= 12.0)
    {
        inch -= 12.0;
        feet++;
    }
    //return temp;
}

int main()
{

    Distance d1(12, 2.4), d2(10, 10.3);
    //Distance d3;
    //d1.Display();
    //d2.Display();
    //d3.Display();

    cout<<endl;
    //d3.sum(d1, d2);
    //d1.Display();
    //d2.Display();
    //d3.Display();
    cout<<endl;
    //d1 = d3;
    Distance d3(d2);
    d1.Display();
    d2.Display();
    d3.Display();


    return 0;
}
