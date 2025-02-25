#include <bits/stdc++.h>

int const Max=5;
using namespace std;


template <class T>

class Stack
{
private:
    T arr[Max];
    int top;
public:
    Stack() { top = -1;}
    void push(T var)
    {
        if(top < Max)
        {
            arr[++top] = var;
            cout<<"Push "<<var<<endl;
        }
        else
            { cout<<"Stack overflow."<<endl; exit(1) ; }
    }
    T pop()
    {
        if(top > 0)
        {
            cout<<"pop ";
            return arr[top--];
        }
        else
           { cout<<"Stack underflow."<<endl; exit(1) ; }
    }
};

int main()
{
    Stack <int> s;
    s.push(1);
    s.push(6);
    s.push(9);
    s.push(90);
    s.push(98);
    cout<< s.pop() <<endl;
    cout<< s.pop() <<endl;
    cout<< s.pop() <<endl;
    return 0;
}
