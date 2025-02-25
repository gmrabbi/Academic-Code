#include <bits/stdc++.h>

using namespace std;


int main()
{
    srand(time(0));
    ofstream outfile("number.txt");
    const int randcount = 100;
    for(int i=0; i<randcount; i++)
    {
        int randnum = rand() % 100+1;
        // cout<<randnum<<endl;
        outfile<<randnum<<endl;
    }
    outfile.close();

    cout<<"Total "<<randcount<<" number generated"<<endl;

    return 0;
}
