/*
#include <bits/stdc++.h>
using namespace std;

class Distance
{
private:
    int feet ;
    float inch;
public:
    Distance(int f=0, float in=0.0):feet(f), inch(in) { }
    void Display()
    { cout<<feet<<"\' - "<<inch<<"\""<<endl; }
    friend Distance operator+(Distance , Distance);
    friend Distance operator+(float , Distance);
//    Distance operator+(int);
    //operator int();

};
*/
/*
// using operator
Distance Distance::operator+(int a)
{
    inch += a;
    feet += a;
    if(inch >= 12.0)
    {
        inch -= 12.0;
        feet++;
    }
    return Distance(feet , inch);
}
*/
/*
//using friend function...
Distance operator+(Distance d1 , Distance d2)
{
    int feet = d1.feet + d2.feet;
    float inch = d1.inch + d2.inch;
    if(inch >= 12.0)
    {
        inch -= 12.0;
        feet++;
    }
    return Distance(feet , inch);
}
*/
/*
Distance operator+(float a, Distance d1)
{
    float inch = a+d1.inch;
    int feet = a+d1.feet;
    if(inch >= 12.0)
    {
        inch -= 12.0;
        feet++;
    }
    return Distance(feet , inch);
}
*/

/*
operator int()
{
    inch += 4;
    feet += 3.3;
    return Distance(feet , inch);
}
*/
/*
int main()
{
    Distance d1(2, 9.4), d2(11, 5.3) , d3;
    d1.Display();
    d2.Display();

    d3 =  d2 + 10;
    d3.Display();

    return 0;
}
*/

/*
//basic to class
//boj = int

#include <bits/stdc++.h>
using namespace std;

class Distance
{
private:
    int feet ;
    float inch;
public:

    Distance():feet(0), inch(0.0) { }
    Distance(int f, float in):feet(f), inch(in) { }
    void Display()
    {  cout<<feet<<"\' - "<<inch<<"\""<<endl; }
    Distance(int a)
    {
        inch = a ;
        feet = a ;
    }

};

int main()
{
    int x = 10;
    Distance d1(6, 8.9);

    Distance d2;
    d2 = x;
    d2.Display();

    return 0;
}
*/

/*
//class to basic
//using operator int = obj
#include <bits/stdc++.h>
using namespace std;

class Distance
{
private:
    int feet ;
    float inch;
public:

    Distance():feet(0), inch(0.0) { }
    Distance(int f, float in):feet(f), inch(in) { }
    void Display()
    {  cout<<feet<<"\' - "<<inch<<"\""<<endl; }
    operator float()
    {
        float fracfeet = inch/12;
        fracfeet += float(feet);
        return fracfeet;
    }

};
int main()
{
    Distance d1(6, 88.9);
    d1.Display();

    float k;
    k = d1;
    cout<<k<<endl;

    return 0;
}
*/

//Template class
#include <bits/stdc++.h>
#define Max 5
using namespace std;

template <class T>
class Stack
{
private:
    T arr[Max];
    int top;
public:
    Stack() {top = -1;}
    void puch(T var)
    {
        if(top<Max)
            { arr[++top] = var; cout<<var<<" Push."<<endl; }
        else
            cout<<"Stack Overflow."<<endl;
    }
    void pop()
    {
        if(top>0)
        {
            T c;
            c = arr[top--];
            cout<<c<<" pop."<<endl;
        }
        else
        {
            cout<<"Stack Underflow."<<endl;
        }
    }
};

int main()
{
    Stack <int> s;
    s.puch(1);
    s.puch(2);
    s.puch(3);
    s.puch(4);
    s.puch(5);
    s.puch(6);
    cout<<"========"<<endl;

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    return 0;
}


























