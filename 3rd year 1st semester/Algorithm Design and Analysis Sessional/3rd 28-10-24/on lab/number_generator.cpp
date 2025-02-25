#include <bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(0));
    ofstream outfile("number.txt");
    const int number = 170;
    for(int i=0; i<number; i++)
    {
        outfile<<rand()%10<<endl;
    }
    cout<<"Done"<<endl;


    return 0;
}
