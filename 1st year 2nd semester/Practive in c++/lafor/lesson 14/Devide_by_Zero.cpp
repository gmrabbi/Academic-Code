#include <bits/stdc++.h>

using namespace std;

const int DevideByZero = 0;

float divide(int a , int b) throw (int)
{
    if(b != 0)
    {
        return(a/b);
    }
    throw DevideByZero;
}

int main()
{
    int a , b;
    cin>>a>>b;
    try
    {
        cout<<divide(a, b)<<endl;
    }
    catch(int e)
    {
        if(e==DevideByZero) { cout<<"can't divide by zero."<<endl; }
    }
    return 0;
}
