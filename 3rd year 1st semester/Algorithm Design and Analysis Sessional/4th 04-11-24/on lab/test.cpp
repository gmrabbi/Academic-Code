#include <bits/stdc++.h>

using namespace std;

int main()
{
    auto start = chrono::high_resolution_clock::now();

    int k=0;
    for(int i=0; i<100000; i++)
        k = k / 5+7;

    auto End = chrono::high_resolution_clock::now();

    chrono::duration<double, std::milli> duration = End - start;
    cout<<"Total time: "<<duration.count()<<" MillSecond."<<endl;

    return 0;
}

