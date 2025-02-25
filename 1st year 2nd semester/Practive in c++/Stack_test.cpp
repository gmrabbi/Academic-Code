#include <iostream>
#define Max 3

using namespace std;

int Full = 1;
int Empty = 2;
template <class t>

class Stack
{
private:
    int top;
    t arr[Max];
public:
    //class Full { };
    //class Empty { };

    Stack():top(-1) { }
    void push(t a)
    {
        if(top >= Max-1)
        {  throw Full;   }
        arr[++top] = a;
    }
    t pop()
    {
        if(top<0)
        {  throw Empty ;  }
        return arr[top--];
    }
};

int main()
{
    Stack <float> stk;
    try
    {
        stk.push(0.0);
        stk.push(9.9);
        stk.push(8.9);
        //stk.push(7);


        cout<<stk.pop()<<endl;
        cout<<stk.pop()<<endl;
        cout<<stk.pop()<<endl;
        //cout<<stk.pop()<<endl;
    }
    catch(int a)
    {
        if(a == Full)
        {
            cout<<"Stack is full"<<endl; exit(1);
        }
        if(a == Empty)
        {
            cout<<"Stack is Empty"<<endl; exit(1);
        }
    } /*
    catch(Stack::Full)
        {
            cout<<"Stack is full"<<endl; exit(1);
        }
    catch(Stack::Empty)
        {
            cout<<"Stack is Empty"<<endl; exit(1);
        }
        */
    return 0;
}
