#include <bits/stdc++.h>
using namespace std;

class Alph
{
private:
    int data;
public:
    Alph(int a=0): data(a) { }
    void Display()
    {  cout<<"Data : "<<data<<endl;  }
    Alph(Alph& a)
    {  data = a.data;  cout<<"copy constructor calling ......"<<endl; }
};

int main()
{
    Alph a(5), b;
    a.Display();
    b.Display();

    b = a;
    b.Display();
}
