#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num1 , num2;
    cout<<"Enter a number  : "; cin>>num1;
    cout<<"Enter another number : ";cin>>num2;

    int& a = num1;
    int& b = num2;

    a = a+b;
    b = a-b;
    a = a-b;
    cout<<a<<" - "<<b<<endl;

    return 0;
}
