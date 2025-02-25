// arrover3.cpp
// creates safe array (index values are checked before access)
// uses overloaded [] operator for both put and get

#include <iostream>
using namespace std;
const int Max = 5;

class myclass
{
private:
    int a[Max];
public:
    myclass() {  a[Max]=0 ;}

    void input()
    {
        cout<<"Enter "<<Max <<" value : ";
        for(int i=0; i<Max; i++)
        {
            cin>>a[i];
        }
    }

    int operator[](int pos)
    {
        return a[pos-1];
    }

    void Display()
    {
        for(int i=0; i<Max; i++)
        {
            cout<<a[i]<<endl;
        }
    }
};

int main()
{
    myclass obj;
    obj.input();
    int pos;
    cout<<"Enter position : "; cin>>pos;
    cout<<"Value : "<<obj[pos]<<endl;
    return 0;
}








