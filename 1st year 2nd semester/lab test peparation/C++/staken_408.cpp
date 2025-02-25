// Not working .....
#include <bits/stdc++.h>
#define MAX 5
using namespace std;

class Stack
{
protected:
    int top;
    int arr[MAX];
public:
    Stack():top(-1) { cout<<"calling .base.."<<endl; }

    void push(int var)
    {
        arr[++top] = var;
        cout<<"Push : "<<var<<endl;
    }

    int pop()
    {
        int var = arr[top--];
        cout<<"Pop : "<<var<<endl;
        return var;
    }
};

class Stack2 : public Stack
{
public:
    Stack2():Stack() {/*cout<<"calling .drive.."<<endl;*/}
    void push(int var)
    {
        if(top >= MAX-1)
        {
            cout<<"Error: Stack is full."<<endl;
            exit(1);
        }
        Stack::push( var );
        //cout<<"calling here......"<<endl;
    }
    int pop()
    {
        if(top<0)
        {
            cout<<"Error: Stack is empty."<<endl;
            exit(1);
        }
        Stack::pop();
    }
};

int main()
{
    Stack2 s1;
    s1.push(32);
    s1.push(3);
    s1.push(5);
    s1.push(7);
    s1.push(3);
    s1.push(5);
    s1.push(7);
    s1.pop();
    s1.pop();
    s1.pop();

    return 0;
}

/*
#include <bits/stdc++.h>
#define MAX 5
using namespace std;

template <class T>

class Stack
{
protected:
    int top;
    T arr[MAX];
public:
    Stack():top(-1) { }

    void push(T var)
    {
        arr[++top] = var;
        cout<<"Push : "<<var<<endl;
    }

    T pop()
    {
        T var = arr[top--];
        cout<<"Pop : "<<var<<endl;
        return var;
    }
};

class Stack2 : public Stack
{
public:
    //Stack2():Stack() {}
    void push(T var)
    {
        if(top >= MAX-1)
            cout<<"Stack is full."<<endl; exit(1);
        Stack::push( var );
    }
};

int main()
{
    Stack2 <int> s1;
    s1.push(3);
    s1.push(5);
    s1.push(7);
    s1.pop();
    s1.pop();

    return 0;
}
*/
