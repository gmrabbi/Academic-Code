#include <bits/stdc++.h>

using namespace std;

class Marks
{
private:
    int mark;
public:
    Marks(int m):mark(m) { }
    void Display()
    {  cout<<"Your mark is : "<<mark<<endl;  }
    Marks operator () (int m)
    {  return Marks(m); /* return *this*/   }
};


int main()
{
    Marks m1(55);
    m1.Display();

    m1(44).Display();

    Marks m = m1(33);
    m.Display();
    return 0;g
}
