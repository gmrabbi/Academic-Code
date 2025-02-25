#include <bits/stdc++.h>
using namespace std;

class Counter
{
protected:
    unsigned int cunt ;
public:
    Counter() { }
    Counter(int c ):cunt(c) {  }

    int get_count()
    {
        return cunt;
    }
    Counter operator ++ ()
    {
        return Counter(++cunt);
    }
};

class DnCounter:public Counter
{
public:
    DnCounter() : Counter()
    { }
    DnCounter(int c) : Counter(c)
    {    }
    DnCounter operator -- ()
    {
        return DnCounter(--cunt);
    }
};


int main()
{
    DnCounter c1, c2(100);
    ++c1; ++c1; ++c1;
    cout<<c1.get_count()<<endl;

    --c1;
    cout<<c1.get_count()<<endl;

    return 0;
}
