#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    cout<<setw(4)<<"x "<<setw(6)<<"sqrt(x)"<<setw(6)<<"x^2"<<endl;
    cout.precision(4);
    for(int i=2; i<=20; i++)
        cout<<setw(4)<<i<<" "<<setw(6)<<sqrt(i)<<setw(6)<<i*i<<endl;
    return 0;
}
