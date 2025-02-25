#include <iostream>

using namespace std;

int main()
{
    int n, rev = 0;
    n = 123;
    while(n)
    {
        rev = (rev*10)+(n%10);
        n /= 10;
    }
    cout<<rev;

    return 0;
}
