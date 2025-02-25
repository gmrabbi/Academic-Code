#include <bits/stdc++.h>

using namespace std;

class Phonebook
{
private:
    string name;
    int area_code;
    int prefix;
    int number;
public:
    Phonebook(string n="" ,int a=0, int p=0, int nm=0): name(n), area_code(a), prefix(p), number(nm) {  }

    void inserter()
    {
        cout<<"Name : "; getline(cin, name);
        cout<<"Area Code : "; cin>>area_code;
        cout<<"Prefix : "; cin>>prefix;
        cout<<"Number : "; cin>>number;
    }
    void Display()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Area Code : "<<area_code<<endl;
        cout<<"Prefix : "<<prefix<<endl;
        cout<<"Number : "<<number<<endl;
    }

};


int main()
{
    Phonebook ph;
    ph.inserter();
    ph.Display();


}
