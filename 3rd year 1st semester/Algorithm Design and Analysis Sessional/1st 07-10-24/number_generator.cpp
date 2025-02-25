#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    const int numCount = 10;

    ofstream outFile("number.txt");
    if (outFile.is_open())
    {
        for (int i = 0; i < numCount; i++)
        {
            int randomNum = rand() % 100;
            outFile << randomNum <<endl;
        }
        outFile.close();
        cout << "Random numbers written to number.txt." << endl;
    }
    else
    {
        cerr << "Unable to open file for writing." << endl;
        return 1;
    }

    cout<<numCount<<endl;

    return 0;
}
