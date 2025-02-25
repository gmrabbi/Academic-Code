#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream fout("output.txt");
    ifstream fin("input.txt");

    string str;

    while(!fin.eof())
    {
        getline(fin, str);
        fout<<str<<"\n";
    }

    return 0;
}
