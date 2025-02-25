// counten2.cpp
// constructors in derived class

#include <iostream>
using namespace std;

class Counter
{
protected:
    int cnt;
public:
    Counter():cnt(0) { }
    Counter(int a):cnt(0) { }
    Counter operator++()
    {  return Counter(++cnt);  }
    void Display()
    {  cout<<"Count : "<<cnt<<endl;  }
};

class DnCounter : public Counter
{
public:
    DnCounter():Counter() { }
    DnCounter(int a):Counter(a) { }
    Counter operator--()
    {  return Counter(--cnt);  }
};

int main()
{
    DnCounter c1;
    c1.Display();

    ++c1;++c1;++c1;
    c1.Display();

    --c1;--c1;
    c1.Display();


    return 0;
}
