#include <iostream>

using namespace std;

int count(string str)
{
    int cnt=0;
    for(int i=0; str[i]!='\0'; i++)
    {
        cnt++;
        //cout<<str[i]<<" ";
    }
    return cnt;
}


int main()
{
    string str;
    getline(cin, str);
    cout<<"\nTotal char: "<<count(str)<<endl;
    return 0;
}
