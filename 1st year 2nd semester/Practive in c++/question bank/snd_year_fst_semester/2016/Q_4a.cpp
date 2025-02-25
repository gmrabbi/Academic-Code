#include <iostream>

using namespace std;

class A
{
private:
    int num;
public:
    A(int a=0):num(a) { }
    void display()
    { cout<<"Number is : "<<num<<endl; }
    friend A operator-(A a, A b);

};

A operator-(A a, A b)
{
        A temp;
        temp.num = a.num - b.num;
        return temp;
}

int main()
{
    A a1(3), a2(5), a3;
    a1.display();
    a2.display();
    a3.display();
    cout<<endl;

    a3 = a2 - a1;
    a1.display();
    a2.display();
    a3.display();

    return 0;
}
