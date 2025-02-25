#include <bits/stdc++.h>
using namespace std;

class Counter
{
private :
    unsigned int count;
public:
    Counter(int n = 0 ):count(n){   }

    int get_count() const
    {
        return count;
    }
    // prefix
    Counter operator ++ ()
    {
        return Counter(++count);
    }
    //postfix
    Counter operator ++ (int)
    {
        return Counter(count++);
    }
};

int main()
{
    Counter c1(1), c2;
    c1++;
    cout<<c1.get_count()<<endl;
    c2 = ++c1;
    cout<<c2.get_count()<<endl;
}

