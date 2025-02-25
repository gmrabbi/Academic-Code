#include <bits/stdc++.h>

using namespace std;

class Marks
{
private:
    int sub[3];
public:
    Marks(int a , int b , int c)
    {
        sub[0] = a;
        sub[1] = b;
        sub[2] = c;
    }
    int operator [](int pos)
    {
        return sub[pos];
    }
};

int main()
{
    Marks obj(11, 22,33);
    cout<<obj[1];
    return 0;
}
