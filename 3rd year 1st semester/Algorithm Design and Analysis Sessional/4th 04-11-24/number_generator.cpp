#include <bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(0));
    ofstream outfile("number.txt");
    const int rnum = 10000;

    auto start = chrono::high_resolution_clock::now();
    for(int i=0; i<rnum; i++)
    {
        outfile<<rand()%10+1<<endl;
    }
    auto End = chrono::high_resolution_clock::now();

    chrono::duration<double, std::milli> duration = End - start;
    cout<<"Total "<<duration.count()<<" milliSecond needed."<<endl;

    cout<<rnum<<" Random number generated."<<endl;

    return 0;
}
