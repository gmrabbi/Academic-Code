#include <bits/stdc++.h>
using namespace std;

class myclass
{
    int num;
public:
    myclass(int i) { num = i; }
    friend bool isneg(int);
};

bool isneg(int a)
{
    return (a<0)?true:false;
}

int main()
{
    myclass my(5);
//    my.isneg(4);
    if(isneg(-3))
        cout<<"True"<<endl;
    else {cout<<"False"<<endl;}
    //cout<<bool(isneg(3);


    return 0;
}
