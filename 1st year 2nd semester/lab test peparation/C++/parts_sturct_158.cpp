// parts.cpp
// uses parts inventory to demonstrate structures
#include <bits/stdc++.h>
using namespace std;

struct part
{
    int id ;
    char name;
    int roll;
};

int main()
{
    part part1;
    cin>>part1.id;
    cin>>part1.name;
    cin>>part1.roll;

    cout<<part1.id<<endl;
    cout<<part1.name<<endl;
    cout<<part1.roll<<endl;

    return 0;
}
