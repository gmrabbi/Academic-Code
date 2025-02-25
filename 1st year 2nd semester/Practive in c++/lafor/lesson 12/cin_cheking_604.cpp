#include <bits/stdc++.h>
using namespace std;
int main()
{
    //string name;
    //write into file
    char c;
    ofstream out("Hello.txt");
    cout<<"Enter your message : ";
    do
    {
        cin>>c; //get_s(name);
        out<<c;
    }while(c !='\n');
    out.close();
    cout<<"write successfully.."<<endl;


    //Read from file
    /*
    ifstream in("Hello.txt");
    in>>name;
    cout<<"welcome "<< name<<endl;
    */
    return 0 ;
}
