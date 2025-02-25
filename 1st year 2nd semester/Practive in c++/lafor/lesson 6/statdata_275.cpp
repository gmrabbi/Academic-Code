#include <bits/stdc++.h>
using namespace std;

class foo
{
private :
     static int counter;
public:
    foo(){counter++;cout<<"called\n"; }
    int getCount()
    {  return counter ;  }
};

int foo::counter = 0;

int main()
{
    foo f1 , f2 , f3;

    cout<<"Counter is "<<f1.getCount()<<endl;
    cout<<"Counter is "<<f2.getCount()<<endl;
    cout<<"Counter is "<<f3.getCount()<<endl;
    return 0;
}


