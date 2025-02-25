#include <bits/stdc++.h>

using namespace std;

class Phonebook
{
private:
    string name;
    //telephone
    int area;
    int prefix;
    int number;
public:
    Phonebook()
    {
        name = "";
        area = 0;
        prefix = 0;
        number = 0;
    }
    void inserter()
    {
        cout<<"Enter name : "; cin>>name;
        cout<<"Enter area code : "; cin>>area;
        cout<<"Enter Prefix of the number : "; cin>>prefix;
        cout<<"Enter Number : "; cin>>number;

    }
    void Display()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Area Code : "<<area<<endl;
        cout<<"Prefix : "<<prefix<<endl;
        cout<<"Number : "<<number<<endl;
    }

};

int main()
{
    Phonebook ph;
    ph.inserter();
    ph.Display();

    return 0;
}
