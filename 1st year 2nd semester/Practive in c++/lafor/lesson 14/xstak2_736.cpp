/*
#include <bits/stdc++.h>
#define max 3

using namespace std;

class Stack
{
private:
    int st[max];
    int top;
public:
    class Full { };
    class Empty { };
    Stack() { top = -1; }

    void push(int val)
    {
        if(top>= max-1)
            throw Full();
        st[++top] = val;
        cout<<val<<" Push"<<endl;
    }

    void pop()
    {
        if(top<0)
            throw Empty();
        int val = st[top--];
        cout<<val<<" Pop"<<endl;
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
        //s1.push(4);
        s1.pop();
        s1.pop();
        s1.pop();
        //s1.pop();
    }
    catch (Stack::Empty)
    {
        cout<<"Stack is Empty."<<endl; exit(1);
    }
    catch (Stack::Full)
    {
        cout<<"Stack is Full."<<endl; exit(1);
    }
    cout<<"Normal execution."<<endl;
    return 0;
}
*/

#include <bits/stdc++.h>
#define max 3
using namespace std;

template <class T>

class Stack
{
private:
    int top;
    T ST[max];
public:
    Stack() { top = -1; }
    class Full { };
    class Empty { };
    void Push(T var)
    {
        if(top >= max-1)
        {
            throw Full();
        }
        ST[++top] = var;
        cout<<var<<" Push."<<endl;
    }
    void Pop()
    {
        if(top<0)
        {
            throw Empty();
        }
        T var = ST[top--];
        cout<<var<<" pop........"<<endl;
    }
};

int main()
{
    Stack <int> s1;
    try
    {
        s1.Push(1);
        s1.Push(2);
        s1.Push(3);
        s1.Pop();
        s1.Push(4);
        s1.Pop();
        s1.Pop();
        s1.Pop();
        //s1.Pop();
    }
    catch(Stack<int>::Full)
    {  cout<<"Stack is Full"<<endl; exit(1); }

    catch(Stack<int>::Empty)
    {  cout<<"Stack is Empty"<<endl; exit(1); }

    cout<<"Normal execution."<<endl;
    return 0;
}
