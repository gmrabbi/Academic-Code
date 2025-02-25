#include <bits/stdc++.h>
using namespace std;

struct account
{
    char name[80];
    double balance;
    unsigned long account_num;
};

int main()
{
    account ac;
    cout<<"Enter your name : "; cin>>ac.name;
    cout<<"Enter balance : "; cin>>ac.balance;
    cout<<"Enter user id : "; cin>>ac.account_num;

    cout<<"Id : "<<ac.account_num<<endl;
    cout<<"Name : "<<ac.name<<endl;
    cout<<"Balance : "<<ac.balance<<endl;

}
