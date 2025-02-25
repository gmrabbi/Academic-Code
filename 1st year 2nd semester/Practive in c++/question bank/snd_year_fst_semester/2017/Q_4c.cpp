#include <iostream>
#define Max 3

using namespace std;

int Full = 1;
int Empty = 2;
class Stack
{
private:
    int top;
    int arr[Max];
public:
    class Full { };
    class Empty { };
    Stack():top(-1) { }
    void display()
    {
        cout<<"Exist element : "<<endl;
        for(int i=top; i>=0; i--)
            cout<<arr[i]<<endl;
    }
    void push(int a)
    {
        if(top >= Max-1)
        { throw Full(); }
        arr[++top] = a;
    }
    int pop()
    {
        if(top<0)
        { throw Empty(); }
        return arr[top--];
    }
};

int main()
{
    Stack stk;
    try
    {
        stk.push(1);
        stk.push(2);
        stk.push(3);
        //stk.push(3);

        cout<<stk.pop()<<endl;
        cout<<stk.pop()<<endl;
        cout<<stk.pop()<<endl;
        //cout<<stk.pop()<<endl;
    }
    catch(int a)
    {
        if(a==Full)
        { cout<<"Stack is Full."; exit(1); }
        if(a==Empty)
        {  cout<<"Stack is Empty."; exit(1); }
    }
    catch(Stack::Full)
    { cout<<"Stack is Full. cls"; exit(1); }
    catch(Stack::Empty)
    {  cout<<"Stack is Empty. cls"; exit(1); }

    return 0;
}
