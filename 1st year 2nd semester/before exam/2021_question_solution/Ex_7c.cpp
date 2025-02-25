#include <iostream>

using namespace std;

class Paralleglogram
{
protected:
    int n=9;
public:
    virtual void Display()
    { cout<<"Paralleglogram."<<endl; }
};
class Rectangle: virtual public Paralleglogram
{    };
class Rhombus:virtual public Paralleglogram
{  };
class Square: public Rectangle,  public Rhombus
{
public:
    void Display()
    {  cout<<"Square "<<n<<endl;  }
};

int main()
{
    Paralleglogram *Pr;
    Square sq;
    Pr = &sq;

    Pr -> Display();
//    pr -> Display1();

    return 0;
}
