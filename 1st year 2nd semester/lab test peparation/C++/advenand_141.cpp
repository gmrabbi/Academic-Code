#include <bits/stdc++.h>
using namespace std;


int main()
{
    while(1)
    {
    char dir;
    cin>>dir;
    switch(dir)
    {
        case 'e': cout<<"x++\n"; break;
        case 'w': cout<<"x--\n"; break;
        case 'n': cout<<"y--\n"; break;
        case 's': cout<<"y++"<<endl; break;
        default: cout<<"sorry wrong input\n";
    }
    }
    return 0 ;
}
