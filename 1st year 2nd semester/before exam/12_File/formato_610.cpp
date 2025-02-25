// formato.cpp
// writes formatted output to a file, using <<
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    /*
    ofstream fout("output.txt");
    string name;
    cout<<"Enter your name : ";
    getline(cin , name);
    fout<<name;
    fout.close();
    */
    ifstream fin("output.txt");
    string nm;
    while (!fin.eof())
    {
        getline(fin, nm);
        cout<<""<<nm<<endl;
    }
    fin.close();


    //cout<<"Done"<<endl;
    return 0;
}
