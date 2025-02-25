#include <iostream>
using namespace std;

class organization
{
private:
    string name;
    int year;
    string address;
public:
    organization(string nm , int y, string ad)
    {
        name = nm;
        year = y;
        address = ad;
    }
    void print()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Establishment year : "<<year<<endl;
        cout<<"Address : "<<address<<endl;
    }
    ~organization() { cout<<"Bye Bye.."<<endl; }
};

int main()
{
    organization org("abc", 1923, "dhaka, bangladesh");
    org.print();

    return 0;
}
