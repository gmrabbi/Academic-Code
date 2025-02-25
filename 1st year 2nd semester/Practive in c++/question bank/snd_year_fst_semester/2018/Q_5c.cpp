#include <iostream>

using namespace std;

class myclass
{
    int num;
public:
    myclass(int i) { num=i; }
    friend bool isneg(myclass);
};

bool isneg(myclass obj)
{
    return ((obj.num < 0)?true:false);

}

int main()
{
    myclass mcls(-9);
    if(isneg(mcls))
        cout<<"This is negative object"<<endl;
    else
        cout<<"This is positive object."<<endl;

    return 0;
}
