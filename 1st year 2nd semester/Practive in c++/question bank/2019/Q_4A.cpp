#include <bits/stdc++.h>

using namespace std;

const int D_zero = 0;
float divition(float a , float b)
{
    if(b != 0)
        return (a/b);
    else
        throw D_zero;
}

int main()
{
    try
    {
        float a , b;
        cin>>a>>b;
        cout<<divition(a, b)<<endl;
    }
    catch(int e)
    {
        if(e==D_zero)
        {
            cout<<"Can't divide by zero."<<endl;
        }
    }
    return 0;
}
