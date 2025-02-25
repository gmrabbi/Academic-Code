#include <bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(0));

    ofstream outfile("number.txt");
    const int rnum = 10;

    for(int i=0; i<rnum; i++)
    {
        outfile<<(rand()%100)+1<<endl;
    }
    outfile.close();

    cout<<"Total "<<rnum<<" number generated"<<endl;
    return 0;
}
