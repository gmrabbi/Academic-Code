#include <iostream>
#define Max 3
using namespace std;

template <class t>
class Stack
{
protected:
    int top;
    t arr[Max];
public:
    Stack():top(-1) { }
    void push(t val)
    {
        if(top>=Max-1)
        { cout<<"Stack is full."<<endl; exit(1); }
        arr[++top] = val; }
    t pop()
    {
        if(top<0)
        { cout<<"Stack is Empty"<<endl; exit(1); }
        return arr[top--]; }
};
/*
template <class t>
class MdStack :public Stack
{
public:
    MdStack():top(-1) { }
    void push(t val)
    {
        if(top>=Max)
        {  cout<<"Stack is full."<<endl;exit(1);  }
        Stack::push(t val);
    }
    t pop()
    {
        if(top<0)
        {  cout<<"Stack is Empty."<<endl; exit();  }
        Stack::pop();
    }
};
*/
int main()
{
    Stack<char> stk;
    //stk.push(2.1);
    //stk.push(1.5);
    //stk.push(3.4);
    stk.push('a');
    stk.push('b');
    stk.push('c');

    cout<<stk.pop()<<endl;
    cout<<stk.pop()<<endl;
    cout<<stk.pop()<<endl;

    return 0;
}
