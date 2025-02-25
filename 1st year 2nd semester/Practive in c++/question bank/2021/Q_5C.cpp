#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num = 0,temp =0, rev=0;
    cin>>num;
    temp = num;
    while(temp)
    {
        rev = ((rev*10)+(temp%10));
        temp /= 10;
    }
    cout<<"Orginal integer : "<<num<<endl;
    cout<<"Reverse integer : "<<rev<<endl;

    return 0;
}
