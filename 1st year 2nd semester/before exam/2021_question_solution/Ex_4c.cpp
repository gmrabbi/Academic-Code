#include <iostream>
#include <math.h>

using namespace std;

int nv_err = 0;
float my_sqrt(float n)
{
    try
    {
        if(n<0) throw nv_err;
        else return sqrt(n);
    }
    catch(int a)
    {
        cout<<"Negative number not allow."<<endl;exit(1);
    }

}

int main()
{
    int a = 0.0F;
    cout<<my_sqrt(a)<<endl;

}
