#include <iostream>

using namespace std;

class myclass
{
private:
    int x;
public:
    myclass(int a=0){x=a; }
    void show() {cout<<"x = "<<x<<endl; }

    myclass operator+(int a);

    //friend myclass operator+(myclass obj,int a);
    //friend myclass operator+(int a , myclass obj);
};

myclass myclass::operator+(int a)
{
    myclass temp;
    temp.x = x + a;
    return temp;
}



/*
myclass operator+(myclass obj , int a)
{
    myclass temp;
    temp.x = obj.x + a;
    return temp;
}
myclass operator+(int a , myclass obj)
{
    myclass temp;
    temp.x = obj.x + a;
    return temp;
}

*/

int main()
{
    myclass obj1(2), obj2;
    obj1.show();
    obj2.show();

    obj2 = obj1 + 10;
    //obj2 = 10 + obj1;

    obj1.show();
    obj2.show();

    return 0;
}
