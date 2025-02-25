#include <iostream>

using namespace std;

class Distance
{
private:
    int feet;
    float inch;
public:
    Distance(int f=0 , float in=0.0):feet(f), inch(in) { }
    void Display()
    {
        cout<<feet <<"\' - "<<inch<<"\""<<endl;
    }
    friend Distance operator+(Distance , Distance); // ob = ob1 + ob2
    Distance operator++(); //pre-increment ++p
    Distance operator++(int); //post-increment p++
    friend Distance operator+(Distance , int); //obj + int
    friend Distance operator+(int , Distance); //int + obj

};
// ob = ob1 + ob2   ==============================================
Distance operator+(Distance d1 , Distance d2)
{
    Distance temp;
    temp.inch = d1.inch + d2.inch;
    temp.feet = d1.feet + d2.feet;
    if(temp.inch > 12.0)
    {
        temp.inch -= 12.0;
        temp.feet++;
    }
    return temp;
}

//pre-increment ++p  ===========================================
Distance Distance::operator++()
{
    ++feet;
    ++inch;
    if(inch > 12.0)
    {
        inch -= 12.0;
        feet++;
    }
    return *this;
}

//post-increment p++  =====================================
Distance Distance::operator++(int)
{
    feet++;
    inch++;
    if(inch > 12.0)
    {
        inch -= 12.0;
        feet++;
    }
    return *this;
}

//obj + int  ===================================
Distance operator+(Distance d1 , int a)
{
    Distance temp;
    temp.inch = d1.inch + a;
    temp.feet = d1.feet + a;
    if(temp.inch > 12.0)
    {
        temp.inch -= 12.0;
        temp.feet++;
    }
    return temp;
}
// int + obj ============================
Distance operator+(int a , Distance d1)
{
    Distance temp;
    temp.inch = d1.inch + a;
    temp.feet = d1.feet + a;
    if(temp.inch > 12.0)
    {
        temp.inch -= 12.0;
        temp.feet++;
    }
    return temp;
}

// ==============================================
int main()
{
    Distance d1(2, 5.4), d2(4, 7.8), d3;
    d1.Display();
    d2.Display();
    d3.Display();
//  cout<<"d3 object : ";
    cout<<"d3 object : ";
    d3 = d1 + d2;
    d3.Display();

    ++d2;
    cout<<"++d2 object ";
    d2.Display();

    d2++;
    cout<<"d2++ object ";
    d2.Display();

    Distance d4(2, 7.8);
    d4 = d4 + 10;
    cout<<"d4+10 object ";
    d4.Display();

    d4 = 10 + d4;
    cout<<"10 + d4 object ";
    d4.Display();

    //d4 + 4;
    d4.Display();


    //cout<<"working welll...";
    return 0;
}
