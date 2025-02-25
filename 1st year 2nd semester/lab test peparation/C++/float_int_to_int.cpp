#include <bits/stdc++.h>
using namespace std;

int main()
{
    double num;
    cin>>num;

    double nm = num - int(num);
    cout<<int(num);
    long fnum = nm*100000;
    long rev = 0, cnt = 1;
    while(fnum)
    {
        if(fnum%10)
        {

            rev = rev * 10 + (fnum%int(pow(10, cnt++) ) );
            //cout<<fnum%10;
        }
        fnum /= 10;
    }
    cout<<rev;
}
