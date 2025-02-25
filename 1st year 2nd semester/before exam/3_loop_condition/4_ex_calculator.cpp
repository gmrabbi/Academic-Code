#include <iostream>
using namespace std;

int main()
{
    int n1, n2, ans;
    char op, ch=1;
    while(ch)
    {
        cout<<"<Num1> <operator> <Num2>"<<endl;
        cin>>n1>>op>>n2;
        switch(op)
        {
            case '+': ans=n1+n2; break;
            case '-': ans=n1-n2; break;
            case '*': ans=n1*n2; break;
            case '/': ans=n1/n2; break;
            default : ans = 0;
        }

        cout<<"Answer = "<<ans<<endl;

        cout<<"Do another(y/n) : "; cin>>ch;
        ch = (ch=='y')?1:0;
    }
    return 0;
}
