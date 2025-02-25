#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char str[20], temp;
    cout<<"Enter string: ";
    gets(str);
    int n = strlen(str);
    for(int i=0 ; i<int(n/2) ; i++)
    {
        temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
    cout<<"Reverse String : "<<str<<endl;

    return 0;
}
