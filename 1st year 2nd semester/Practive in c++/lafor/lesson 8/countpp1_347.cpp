#include <bits/stdc++.h>

using namespace std;

class Counter
{
    int count;
public:
    Counter(int n=0):count(n)
        {  cout<<"const called."<<endl; }
    void get_count()
    {
        cout<<"From get cnt : "<<count<<" "<<endl;
    }
    void operator ++ ()
    {
        cout<<"from operator : "<<++count<<endl;
    }
};

int main()
{
    Counter c1, c2(5);
    ++c1;
    // c2 = c1;
    c2.get_count();
}
