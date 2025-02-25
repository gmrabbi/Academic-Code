#include <bits/stdc++.h>

using namespace std;

int main()
{
    int sign = -1;
    int n, sum=0;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        sum = sum+ (sign*i);
        sign = sign * (-1);
    }
    cout<<sum<<endl;


    return 0;
}
