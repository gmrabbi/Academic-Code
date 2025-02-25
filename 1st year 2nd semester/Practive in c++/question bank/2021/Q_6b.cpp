#include <bits/stdc++.h>
using namespace std;

class Organization
{
private:
    enum{SZ = 80};
    char name[SZ];
    int year;
    char addr[SZ];
public:
    Organization()
    {
        cout<<"Enter name : "; gets(name);
        cout<<"Establishment year : "; cin>>year;
        cout<<"Enter Address : "; cin>>addr;
    }

    void display()
    {
        cout<<"Organization Name : "<<name<<endl;
        cout<<"Establishment year : "<<year<<endl;
        cout<<"Address : "<<addr<<endl;
    }
    ~Organization()
    {  cout<<"Good bye.."<<endl;  }
};

int main()
{
    Organization org;
    org.display();

    return 0;
}
