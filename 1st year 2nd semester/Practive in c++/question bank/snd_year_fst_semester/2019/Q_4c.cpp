#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

struct account
{
    string name;
    double balance = 500.00 ;
    int stu_id ;
};

int main()
{
    account acc;
    int bln;
    cout<<"Enter your Name : "; getline(cin, acc.name);
    cout<<"Balance : "; cin>>bln;
    acc.balance += bln;
    cout<<"Student Id : "; cin>>acc.stu_id;

    cout<<acc.name<<endl;
    cout<<acc.stu_id<<endl;
    cout<<acc.balance<<endl;

    return 0;
}
