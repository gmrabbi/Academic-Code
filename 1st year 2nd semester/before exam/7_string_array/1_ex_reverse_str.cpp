#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reversit(char *st,int ln )
{
    char c;
    for(int i=0; i<int(ln/2); i++)
    {
        c = st[i];
        st[i] = st[ln-i-1];
        st[ln-i-1] = c;
    }
}

int main()
{
    char str[10];
    cout<<"Enter string : "; gets(str);
    int len = strlen(str);
    cout<<len<<endl;
    reversit(str, len);

    cout<<str<<endl;

    return 0;
}
