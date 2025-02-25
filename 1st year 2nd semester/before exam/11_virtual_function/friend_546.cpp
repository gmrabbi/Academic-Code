// friend.cpp
// friend functions
#include <iostream>
using namespace std;

class Beta;
class Alpha
{
private:
    int data;
public:
    Alpha():data(3) { }
    friend int addition(Alpha , Beta );
};

class Beta
{
private:
    int data;
public:
    Beta():data(7) { }
    friend int addition(Alpha , Beta );
};

int addition(Alpha a, Beta b)
{
    return (a.data + b.data);
}


int main()
{
    Alpha aa;
    Beta bb;
    cout<addition(aa, bb)<<endl;
    return 0;
}
