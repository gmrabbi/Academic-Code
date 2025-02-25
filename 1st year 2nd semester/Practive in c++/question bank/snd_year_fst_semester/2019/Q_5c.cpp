#include <iostream>
using namespace std;

class Int
{
private:
    int num;
public:
    Int():num(0) { }
    Int(int a):num(a) { }
    void Display()
    {  cout<<"Number : "<<num<<endl;  }
    Int operator+(Int a)
    {
        Int t;
        t.num = num + a.num;
        return t;
    }
};

int main()
{
    Int a(3), b(4), c;
    c = a+b;
    a.Display();
    b.Display();
    c.Display();

    return 0;
}
