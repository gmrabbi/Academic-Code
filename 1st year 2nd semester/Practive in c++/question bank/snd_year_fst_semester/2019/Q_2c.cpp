#include <iostream>
#include <math.h>

using namespace std;

double rnd_fn(double *dd)
{
    //cout<<*dd<<endl;
    return round(*dd);
}


int main()
{
    double a = 4.45;
    cout<<rnd_fn(&a)<<endl;

    return 0;
}
