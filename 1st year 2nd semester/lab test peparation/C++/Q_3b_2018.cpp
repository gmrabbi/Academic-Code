#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << fixed << setprecision(3);

    cout << setw(10) << "X"
         << setw(10) << "sqrt(X)"
         << setw(10) << "X^2" << endl;

    for(int i = 2 ; i<= 10 ; i++)
    {
        cout << setw(10) << i
         << setw(10) << sqrt(i)
         << setw(10) << int(pow(i, 2)) << endl;
    }
}
