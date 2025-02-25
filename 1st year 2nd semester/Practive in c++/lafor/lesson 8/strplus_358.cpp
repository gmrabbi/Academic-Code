#include <bits/stdc++.h>

using namespace std;

class String
{
private:
    enum {sz=80};
    char str[sz];
public:
    String()
        { str[0]='\0'; }
    String(char s[])
        { strcpy(str, s); }
    void Display() { cout<<str<<endl; }
    String operator +(String);
};

String String::operator+(String ss)
{
    String temp;
    if((strlen(str) + strlen(ss.str))>sz )
        cout<<"Overflow"<<endl;
    else
        {
            strcpy(temp.str, str);
            strcat(temp.str, ss.str);
        }
    return temp;
}
int main()
{
    String s1= "Golam mostafa ";
    String s2 = "Rabby";

    s1.Display();
    s2.Display();

    s1 = s1+s2;

    s1.Display();
    return 0;
}
