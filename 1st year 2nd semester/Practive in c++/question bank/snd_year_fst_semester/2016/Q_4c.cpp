#include <iostream>

using namespace std;

int input_error = 1;
int division_zero = 0;

int main()
{
    int a , b;
    try
    {
        cout<<"a = "; cin>>a;
        cout<<"b = "; cin>>b;
        if(cin.fail())
            throw input_error;
        if(b==0)
            throw division_zero;
        cout<<a<<"/"<<b<<" = " <<a/b<<endl;
    }
    catch(int a)
    {
        if(a == input_error)
        { cout<<"Input error."<<endl; exit(1); }
        if(a == division_zero)
        { cout<<"Division by zero."<<endl; exit(1); }
    }
}
