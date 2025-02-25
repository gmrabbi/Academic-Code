#include <bits/stdc++.h>
#define max 3

using namespace std;

class Stack
{
private:
    int st[max];
    int top;
public:
    class Range
    {   };
    Stack() { top =-1; }

    void push(int var)
    {
        if(top>=max -1)
            throw Range();
        st[++top] = var;
        cout<<var <<" push."<<endl;
    }
    int pop()
    {
        if(top<0)
            throw Range();
        int var = st[top--];
        cout<<var<<" pop."<<endl;
    }
};

int main()
{
    Stack s1;
    try
     {
        s1.push(1);
        s1.push(2);
        s1.push(3);

        s1.pop();
        s1.pop();
        s1.pop();
        s1.pop();
    }
    catch (Stack::Range)
    {
        cout<<"Stack is full or empty."<<endl;
        exit(1);
    }
    cout<<"Normal execution."<<endl;

    return 0;
}
