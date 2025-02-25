// Write operation of txt file
#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*
    string name;
    cout<<"Enter your name : ";
    getline(cin, name);
    ofstream out("input.txt");
    out<<name;
    */

    ofstream out;
    out.open("output.txt");
    out<<"Hello world.!";
    out<<"\nAnother write operation.";
    out.close();
    return 0;
}
