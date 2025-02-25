#include <bits/stdc++.h>
using namespace std;

int main()
{
    ofstream out;
    out.open("name.txt");
    out<<"This is G.M.Rabby\n";
    out<<"Thank you.";
    out.close();

    string name;
    ifstream in;
    in.open("name.txt");
    //in>>name ;
    while(in.eof() == 0)
    {
        getline(in , name);
        cout<<name<<endl;
    }
    in.close();



    return 0;
}
