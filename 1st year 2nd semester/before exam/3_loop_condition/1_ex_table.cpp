#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n=7;
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=10; j++)
            cout<<setw(4)<<j*n*i ;
        cout<<endl;
    }
}
