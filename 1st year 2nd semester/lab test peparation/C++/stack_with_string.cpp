#include <bits/stdc++.h>
#define MAX 80

using namespace std;
template <class T>

class Stack
{
private:
    T arr[MAX];
    int top;
public:
    Stack(): top(-1) { }
    void push(T var)
    {
        cout<<"push : "<<var<<endl;
        arr[++top] = var;
    }
    T pop()
    {
        return arr[top--];
    }
};

int main()
{
    Stack <char>s;
    s.push('a');
    s.push('b');
    cout<<"pop : "<<s.pop()<<endl;

    return 0;
}
