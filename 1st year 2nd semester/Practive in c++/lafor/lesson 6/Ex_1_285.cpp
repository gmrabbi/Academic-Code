#include <bits/stdc++.h>

using namespace std;

class Int
{
    private:
        int value ;
    public:
        Int(): value(0)
        { }
        Int(int val )
        {
            value = val;
        }
        void Display()
        {
            cout<<value<<endl;
        }
        Int add(Int other)
        {
            return Int(value + other.value);
        }
};

int main()
{
    Int x;
    Int a(5);
    Int b(10);

    x = a.add(b);
    x.Display();
    return 0;
}
