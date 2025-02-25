#include <iostream>

using namespace std;

class myclass
{
    int num;
public:
    myclass(int i) {num =i; }
    friend bool isneg(myclass b)
    { return ((b.num<0)?true: false);  }
    myclass(myclass& a)
    {  num = a.num; cout<<"copy"<<endl; }
    myclass operator=(myclass m)
    {
        num = m.num;
        cout<<"="<<endl;
        return *this;
    }
};

int main()
{
    myclass cls(-5);
    if(isneg(cls)) { cout<<"negative."<<endl; }
    //myclass t2(cls);
    myclass t1 = cls;

}
