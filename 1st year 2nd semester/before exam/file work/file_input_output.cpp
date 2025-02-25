#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream fout("test");
    fout<<"hello ";
    fout<<100<<" "<<hex<<64<<endl;
    fout.close();

    ifstream fin("test");
    //char str[80];
    string str;
    int i;
    cout<<str<<" str."<<endl;
    //getc(str , fin);
    //fin>>str >>i;
    //cout<<str<<' '<<i<<endl;

    getline(fin, str);
    cout<<str;
    fin.clear();
    //cout<<"Done"<<endl;
    return 0;
}
