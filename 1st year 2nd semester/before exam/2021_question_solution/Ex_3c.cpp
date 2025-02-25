#include <iostream>
#define maxx(a,b) ((a>b)?a:b)

using namespace std;

static int add(int a, int b) { return a+b; }

int main()
{

    int a=44, b=6;
    cout<<maxx(a, b)<<endl;
    cout<<add(a, b)<<endl;
    //cout<<add(a, b)<<endl;
    return 0;
}
