#include <bits/stdc++.h>

using namespace std;

int main()
{
    ofstream outfile("output.txt");
    ifstream infile("read_write_two_file.cpp");

    string str;

    if(outfile.is_open() && infile.is_open())
    {
        while(getline(infile , str))
        {
            outfile<<str<<endl;
        }
    }
    outfile.close();
    infile.close();
    cout<<"write successfully.."<<endl;

    return 0;
}
