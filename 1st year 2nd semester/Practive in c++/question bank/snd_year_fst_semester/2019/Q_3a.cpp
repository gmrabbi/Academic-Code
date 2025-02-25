#include <iostream>

using namespace std;

int main()
{
    string s = "hello";
    double n = 22.23553;

    cout.fill('%');
    cout.width(.3);
    cout<<s<<endl;


    cout.precision(3);
    cout<<n<<endl;



}
