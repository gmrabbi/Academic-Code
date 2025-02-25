#include <bits/stdc++.h>

using namespace std;

class Counter
{
    unsigned int count;
public:
    Counter(int n = 0):count(n)
        { }
    unsigned int get_count()
    {
        return count;
    }

    Counter operator ++ ()
    {
        //++count;
        //Counter temp;
        //temp.count = ++count;
        return Counter(++count);
    }
};


int main()
{
    Counter c1, c2;
    ++c1;
    cout<<c1.get_count()<<endl;
    c2 = ++c1;
    cout<<c1.get_count()<<endl;
    cout<<c1.get_count()<<endl;
}
