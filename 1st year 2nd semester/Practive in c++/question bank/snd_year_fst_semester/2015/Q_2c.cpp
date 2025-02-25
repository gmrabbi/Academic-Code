#include <iostream>

class distance
{
private:
    int feet;
    float inches;
public:
    distance():feet(0), inches(0.0) { }
    distance(int f, float i):feet(f), inches(i) { }
    friend distance operator+(distance , distance);
    friend distance operator+(int , distance);
    friend distance operator+(distance , int);

};

distance operator+(distance d1, distance d2) //d3 = d1 + d2
{
    distance temp;
    temp.feet = d1.feet + d2.feet;
    temp.inches = d1.inches + d1.inches;
    if(temp.inches >= 12.0)
    {
        temp.feet++;
        temp.inches-= 12.0;
    }
    return temp;
}

distance operator+(int d1, distance d2) //d3 = 10 + d2
{
    distance temp;
    temp.feet = d1 + d2.feet;
    temp.inches = d1 + d2.inches;
    if(temp.inches >= 12.0)
    {
        temp.feet++;
        temp.inches-= 12.0;
    }
    return temp;
}

distance operator+(distance d1, int d2) //d3 = d1 + 10
{
    distance temp;
    temp.feet = d1.feet + d2;
    temp.inches = d1.inches + d2;
    if(temp.inches >= 12.0)
    {
        temp.feet++;
        temp.inches-= 12.0;
    }
    return temp;
}

int main()
{

    distance D1, D2, D3;
    D1 = D1 + 10;
    D2 = 20 + D2;
    D3 = D1 + D2;

    return 0;
}
