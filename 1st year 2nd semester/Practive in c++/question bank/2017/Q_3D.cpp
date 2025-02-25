#include <iostream>
#include <string>
using namespace std;

int main()
{
    char str[] = "123456789";
    int n = 5;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n-i; j++)
            cout<<" ";
        for(int j=1; j<=(2*i)-1; j++)
            cout<<str[j];
        cout<<endl;
    }


    return 0;
}
