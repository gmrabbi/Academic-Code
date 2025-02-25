#include <bits/stdc++.h>
#define MAXIMUM 10+1
using namespace std;


const int Full = 1;
const int Empty = 2;
class Stack
{
private:
    int arr[MAXIMUM];
    int top;
public:
    Stack()
    {
        arr[0] = '\0';
        int top = -1;
    }
    void push(int var)
    {
        if(top>= MAXIMUM)
            throw Full;
        arr[++top] = var;
    }
    int pop()
    {
        if(top<=0)
            throw Empty;
            //cout<<"Stack is underflow."<<endl;
        return arr[top--];
    }
    void display()
    {
        cout<<"Remain content : "<<endl;
        int i = top;
        for(i; i>0; i--)
            cout<<arr[i]<<endl;
    }
};

int main()
{
    try{
        Stack st;
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(5);
        st.push(6);
        st.push(7);
        st.push(8);
        st.push(9);
        st.push(10);
        //st.push(11);
        //st.push(12);

        cout<<st.pop()<<" pop."<<endl;
        cout<<st.pop()<<" pop."<<endl;
        cout<<st.pop()<<" pop."<<endl;
        cout<<st.pop()<<" pop."<<endl;
        cout<<st.pop()<<" pop."<<endl;
        cout<<st.pop()<<" pop."<<endl;
        cout<<st.pop()<<" pop."<<endl;
        cout<<st.pop()<<" pop."<<endl;
        cout<<st.pop()<<" pop."<<endl;
        cout<<st.pop()<<" pop."<<endl;
        //cout<<st.pop()<<" pop."<<endl;

        st.display();
    }
    catch(int e)
    {
        if(e==1)
            cout<<"Stack overflow."<<endl;
        else if(e==2)
            cout<<"Stack underflow."<<endl;
    }
}

