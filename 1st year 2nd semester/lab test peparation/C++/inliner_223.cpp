#include <bits/stdc++.h>

using namespace std;

inline float lbstokg(float lb)
{
    return lb*0.453592;
}

int main()
{
    float lb;
    cout<<"Enter your weight in lb : "; cin>>lb;
    cout<<lb <<" = "<<lbstokg(lb)<<endl;
}
