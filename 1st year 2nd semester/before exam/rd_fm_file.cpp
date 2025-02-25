#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("rd_fm_file.cpp");
    string str;

    while(!fin.eof())
    {
        getline(fin, str);
        cout<<str<<endl;
    }

    return 0;
}
