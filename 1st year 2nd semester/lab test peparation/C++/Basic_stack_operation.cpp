#include <bits/stdc++.h>
#define MAX 80

using namespace std;

class Stack
{
private:
    int arr[MAX];
    int top;
public:
    Stack(): top(-1) { }

    void push(int var)
    {
        arr[++top] = var;
        cout<<"push : "<<var<<endl;
    }
    int pop()
    {
        return arr[top--];

    }

};

int main()
{
    Stack s;
    s.push(10);
    s.push(5);
    cout<<"pop : "<<s.pop();
    return 0;
}
