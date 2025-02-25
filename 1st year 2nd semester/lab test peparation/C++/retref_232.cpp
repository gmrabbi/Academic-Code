#include <bits/stdc++.h>

using namespace std;

int x;
int& setx()
{
    return x;
}

int main()
{
    setx() = 34;
    cout<<x;
    return 0;
}
