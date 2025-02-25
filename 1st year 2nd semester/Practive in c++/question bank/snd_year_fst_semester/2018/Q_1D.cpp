#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    int result1 = add(3, 5);       // Calls add<int>(3, 5)
    double result2 = add(1.5, 2.5); // Calls add<double>(1.5, 2.5)

    cout << "Result 1: " << result1 << endl;
    cout << "Result 2: " << result2 << endl;

    return 0;
}

/*
#include <iostream>
using namespace std;


int min(int a, int b)
{
    return ((a < b) ? a : b);
}

float min(float a, float b)
{
    return ((a < b) ? a : b);
}

double min(double a, double b)
{
    return ((a < b) ? a : b);
}

int main()
{
    int a = 3, b = 5;
    float x=8.9, y=7.9;
    double p=2.34, q=9.08;
    cout << min(a, b) << endl;
    cout << min(x, y) << endl;
    cout << min(p, q) << endl;
    return 0;
}
*/
