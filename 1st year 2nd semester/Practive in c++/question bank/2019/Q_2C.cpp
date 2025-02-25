#include <iostream>
using namespace std;

int main()
{
    int num = 10;
    int& n = num;
    n++;
    cout<<num;

    return 0;
}
