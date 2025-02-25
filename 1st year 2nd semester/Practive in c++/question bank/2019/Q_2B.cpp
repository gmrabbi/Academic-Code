#include <bits/stdc++.h>

using namespace std;

inline int average(int a , int b)
{ return (a+b)/2; }

inline double average(double a , double b)
{  return (a+b)/2;  }

int main()
{
    int x , y;
    double a, b;
    cout<<"Enter 2 int num : ";
    cin>>x>>y;

    cout<<"Enter 2 double num : ";
    cin>>a>>b;

    cout<<"int avg : "<<average(x ,y)<<endl;
    cout<<"Double avg : "<<average(a, b)<<endl;

    cout<<round(2.7)<<endl;

    return 0;
}
