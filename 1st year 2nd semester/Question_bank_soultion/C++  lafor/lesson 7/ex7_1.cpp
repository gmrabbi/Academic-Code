// ex7_1.cpp
// reverses a C-string
#include <bits/stdc++.h>
#define max 80

using namespace std;

char str[max];

void recstr(char c[])
{
    int len = strlen(c);
    for(int i=0; i<len/2; i++)
    {
        char temp;
        temp = c[i];
        c[i] = c[len-i-1];
        c[len-i-1] = temp;
    }
    cout<<c;
}

int main()
{
    char name[max] = "golam rabby";
    recstr(name);
    cout<<str<<endl;
    return 0;
}
