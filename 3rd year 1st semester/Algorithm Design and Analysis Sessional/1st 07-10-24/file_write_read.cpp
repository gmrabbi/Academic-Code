#include <iostream>
#include <fstream>
#include <vector>
// #include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int numCount = 100;
    vector<int> numbers;

    // Seed the random number generator
    srand(static_cast<int>(time(0)));

    // Generate random numbers and write to file
    ofstream outFile("number.txt");
    if (outFile.is_open())
    {
        for (int i = 0; i < numCount; ++i)
        {
            int randomNum = rand() % 1000; // Generate random number between 0 and 999
            numbers.push_back(randomNum);
            outFile << randomNum <<endl; // Write random number to file
        }
        outFile.close();
        cout << "Random numbers written to number.txt." << endl;
    }
    else
    {
        cerr << "Unable to open file for writing." << endl;
        return 1;
    }

    // Read the numbers back from the file
    ifstream inFile("number.txt");
    if (inFile.is_open())
    {
        cout << "Reading numbers from number.txt:" << endl;
        int num;
        while (inFile >> num)
        {
            cout << num << endl; // Print each number read from the file
        }
        inFile.close();
    }
    else
    {
        cerr << "Unable to open file for reading." << endl;
        return 1;
    }

    return 0;
}
