// staken.cpp
// overloading functions in base and derived classes
#include <iostream>
using namespace std;
const int Max = 3;

class Stack
{
protected:
    int top;
    int arr[Max];
public:
    Stack():top(-1) { }
    void push(int a)
    { arr[++top] = a; }
    int pop()
    { return arr[top--]; }
};
class MdStack: public Stack
{
public:
    void push(int a)
    {
        if(top>=Max-1)
        {  cout<<"Stack is full."<<endl; exit(1); }
        Stack::push(a);
    }
    int pop()
    {
        if(top<0)
        {  cout<<"Stack is Empty"<<endl; exit(1);   }
        Stack::pop();
    }
};

int main()
{
    MdStack stk;
    stk.push(1);
    stk.push(3);
    stk.push(2);
    //stk.push(1);
    cout<<stk.pop()<<endl;
    cout<<stk.pop()<<endl;
    cout<<stk.pop()<<endl;
    cout<<stk.pop()<<endl;


    return 0;
}



















