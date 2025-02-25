#include <bits/stdc++.h>

using namespace std;

char c ;
void getcha()
{
    static int cnt ;
    cin>>c;
    cout<<cnt++<<endl;;
}
void putcha()
{
    cout<<c;
}


int main()
{
    putcha();
    getcha();
    putcha();

    putcha();
    getcha();
    putcha();

    putcha();
    getcha();
    putcha();
    //cout<<cnt;
    return 0;
}
