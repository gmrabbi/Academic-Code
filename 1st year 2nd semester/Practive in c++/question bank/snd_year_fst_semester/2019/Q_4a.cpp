#include <iostream>
using namespace std;

int error = 0;
class Distance
{
public:
    //Distance()
    class range
    { };
    int divider(int a, int b) //throw(int)
    {
        try
        {
            if(b==0)
                throw range();
            else
                return ( a/b) ; //<<endl;
        }
        catch (Distance::range)
        {
            if(a==error)
            {
                cout<<error<<" devision error."<<endl;exit(1);
            }
            cout<<"got it.."<<endl;
        }
    }
};


int main()
{
    Distance dd;

    cout<<dd.divider(4, 0);

}
