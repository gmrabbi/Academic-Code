#include <iostream>

using namespace std;

class Distance
{
private:
    int feet;
    float inch;
public:
    Distance(int ft=0, float in=0.0):feet(ft), inch(in) { }
    void getData()
    {
        cout<<"Feet : "; cin>>feet;
        cout<<"Inch : "; cin>>inch;
    }
    void Display()
    {  cout<<feet<<"\' - "<<inch<<"\""<<endl;  }
    //   d3.addobjects(d1, d2);
    void addobjects(Distance d1 , Distance d2) // d3 = addobjects(d1, d2);
    {
        int feet = d1.feet + d2.feet;
        float inch = d1.inch + d2.inch;
        if(inch>=12.0)
        {
            inch -= 12.0;
            feet++;
        }
        //Distance(feet, inch);
        cout<<feet<<"\' - "<<inch<<"\""<<endl;
        //Display();
    }
    //   d3 = d1.addobjects(d2);

    Distance Adding(Distance d) //d3 = d2.Adding(d1);
    {
        feet += d.feet;
        inch += d.inch;
        if(inch>=12.0)
        {
            inch -= 12.0;
            feet++;
        }
        return Distance(feet , inch);
        //cout<<feet<<"\' - "<<inch<<"\""<<endl;
    }
    Distance operator=(Distance d) //d1 = d2;
    {
        feet = d.feet;
        inch = d.inch;
        //cout<<"calling......."<<endl;
        return Distance(d.feet , d.inch);
    }

    Distance operator+(Distance d) //d3 = d1+d2;
    {
        Distance temp;
        temp.inch = d.inch + inch;
        temp.feet = d.feet + feet;
        if(temp.inch >= 12.0)
        {
            temp.feet++;
            temp.inch -= 12.0;
        }
        return temp;
    }

    Distance operator-()
    {

        feet = -feet;
        inch = -inch;
        return *this;
    }
    Distance operator++(int)
    {
        ++feet;
        ++inch;
        if(inch>=12.0)
        {
            feet++;
            inch-=12.0;
        }
        return *this;
    }
    bool operator<(Distance d)
    {
        float f1 = feet+(inch/12);
        float f2 = d.feet+(d.inch/12);
        return (f1<f2)?true:false;
    }
    void operator+=(Distance d)
    {
        inch += d.inch;
        feet += d.feet;
        if(inch>=12.0)
        {
            feet++;
            inch-=12.0;
        }
        //return Distance(feet , inch);
    }

};

int main()
{
    Distance dist1(10, 10.50), dist2, dist3;
    dist2.getData();
    //dist3.addobjects(dist1 , dist2);

    //dist3 = dist1.Adding(dist2);
    dist3 = dist1 + dist2;
    //dist3 = -dist2;
    dist3++;
    dist3.Display();
    if(dist1 < dist2)
        cout<<"Dist2 is grather than dist1"<<endl;
    else
        cout<<"Dist2 is not grather than dist1"<<endl;

    dist3 += dist1;
    dist3.Display();
    cout<<endl;
    dist1.Display();
    dist2.Display();
    dist3.Display();

    return 0;
}
