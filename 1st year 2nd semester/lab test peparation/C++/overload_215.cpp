#include <bits/stdc++.h>

using namespace std;

void Display()
{
    for(int i = 0 ; i<40 ; i++)
        cout<<"*";
    cout<<endl;
}

void Display(char c)
{
    for(int i = 0 ; i<40 ; i++)
        cout<<c;
    cout<<endl;
}

void Display(char c , int n)
{
    for(int i = 0 ; i<n ; i++)
        cout<<c;
    cout<<endl;
}

int main()
{
    Display();
    Display('=');
    Display('*' , 43);
    return 0 ;
}
