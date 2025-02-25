#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int fst = a;
    int snd = 0;

    if(a==b)
    {
        if(b==c)
        {
            cout<<"Equal"<<endl;
            return 0;
        }
    }

    if(b>fst)
    {
        snd = fst;
        fst = b;
    }
    if(c>fst)
    {
        snd = fst;
        fst = c;
    }

    if(a<fst)
    {
        if(a>snd)
            snd = a;
    }
    if(b<fst)
    {
        if(b>snd)
            snd = b;
    }
    if(c<fst)
    {
        if(c>snd)
            snd = c;
    }

    cout << "a=" << a << " b=" << b << " c=" << c << endl;
    cout << "first=" << fst << " \nsnd=" << snd << endl;

    return 0;
}
