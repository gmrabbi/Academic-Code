#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    for(float i=0.25; i<=1.0; i=i+0.25)
    {
        cout.precision(5);
        cout.width(7);
        cout<<i;
        cout.width(10);
        cout<<i*i<<"\n";
    }
    cout<<"-------------------------"<<endl;
    cout<<setw(10)<<"TOTAL=" <<setw(20) <<setprecision(2)<<14.58<<endl;
    return 0;
}
