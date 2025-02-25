#include <bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(0));
    const int randnum = 5;

    ofstream outFile("number.txt");

    for(int i=0; i< randnum; i++)
    {
        int rnum = rand() % 100+1;
        outFile<<rnum<<endl;
    }
    outFile.close();
    cout<<randnum<<endl;
    cout<<"Done"<<endl;

    return 0;
}

