#include <iostream>

using namespace std;

int err = 0;

int main()
{
    int num;
    try
    {
        cin>>num;
        if(cin.fail())
            throw err;
    }
    catch(int a)
    {
        if(a==err)
        {
            cout<<"An error happend."<<endl;
        }
    }

    return 0;
}
