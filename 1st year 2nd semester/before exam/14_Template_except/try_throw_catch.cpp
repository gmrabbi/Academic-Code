#include <iostream>
#define Max 5

using namespace std;
//template <class t>

class Stack
{
private:
    int top;
    int arr[Max];
public:
    class Range { };
    class Full { };
    class Empty { };

    Stack():top(-1) { }
    void push(int val)
    {
        if(top>=Max-1)
            throw Full();
        arr[++top] = val;
    }
    int pop()
    {
        if(top<0)
            throw Empty();
        return arr[top--];
    }
};

int main()
{
    Stack  stk;
    try
    {
        stk.push(1);
        stk.push(3);
        stk.push(2);
         stk.push(3);
        stk.push(2);
         stk.push(3);
        stk.push(2);

        cout<<stk.pop()<<endl;
        cout<<stk.pop()<<endl;
        cout<<stk.pop()<<endl;
         cout<<stk.pop()<<endl;
        cout<<stk.pop()<<endl;
        cout<<stk.pop()<<endl;
    }
    catch(Stack::Full)
    {  cout<<"Stack Full."<<endl;  }
    catch (Stack::Empty)
    {  cout<<"Stack Empty."<<endl;  }

    cout<<"\nNormal Statement."<<endl;
}








