#include <iostream>
#include <bits/stdc++.h>
#define Max 5

using namespace std;

int summation(int *a, int sz)
{
    int sum =0;
    for(int i=0; i<sz; i++)
        sum += a[i];
    return sum;
}

double summation(double *a, int sz)
{
    //int ln = strlen(a);
    double sum =0.0;
    for(int i=0; i<sz; i++)
        sum += a[i];
    return sum;
}

int main()
{
    int str[Max]={1, 5,3,8, 1};
    double str1[Max] = {1.2, 2.3 , 3.4, 4.5, 1.3};
    cout<<str1.length()<<endl;
    cout<<summation(str, 5)<<endl;
    cout<<summation(str1, 5)<<endl;

    return 0;
}
