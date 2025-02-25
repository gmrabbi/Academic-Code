#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class person
{
private:
    char name[80];
public:
    void getName()
       {  cout<<"Enter Name : "; cin>>name;  }
    void putName()
    {  cout << "Name is : " << name <<endl;  }
    virtual void getData() = 0;
    virtual bool isoutstanding() = 0;
};

class student : public person
{
private:
    double gpa;
public:
    void getData()
    {
        person::getName();
        cout<<"Enter G.P.A "; cin>>gpa;
    }
    bool isoutstanding()
    {
        return (gpa>3.5)?true: false;
    }
};

class professor : public person
{
private:
    int numpub;
public:
    void getData()
    {
        person::getName();
        cout<<"Enter publisher number : ";cin>>numpub;
    }
    bool isoutstanding()
    {
        return (numpub>100)?true: false;
    }
};


int main()
{
    person *perArr[100];
    int n;
    char choice;
    do
    {
        cout<<"Data for student or professor (s/p) ?";
        cin>>choice;
        if(choice == 's')
            perArr[n] = new student;
        else
            perArr[n] = new professor;
        perArr[n++] ->getData();
        cout<<"     Enter another (y/n)"<<endl;
        cin>>choice;
    }while(choice == 'y');

    for(int i = 0 ; i<n ; i++)
    {
        perArr[i] -> putName();
        if(perArr[i]->isoutstanding())
            cout<<"❤ This person is outstanding."<<endl;
    }
    return 0;
}
