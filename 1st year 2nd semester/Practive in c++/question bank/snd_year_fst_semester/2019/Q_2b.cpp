#include <iostream>
using namespace std;

inline int average(int a , int b)
{ return (a+b)/2; }

inline double average(double a, double b)
{ return(a+b)/2; }

int main()
{
    int a=4, b=5;
    double x=4.5, y = 3.4;
    cout<<average(a, b)<<endl;
    cout<<average(x, y)<<endl;

    return 0;
}
