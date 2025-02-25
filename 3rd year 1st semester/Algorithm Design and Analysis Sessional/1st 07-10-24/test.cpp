#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <chrono>

using namespace std;

vector<int> a;
vector<int> b;

void Merge(int low, int mid, int high)
{
    int h = low;
    int i = low;
    int j = mid+1;

    while((h<=mid) && (j<=high))
    {
        if(a[h]<=a[j])
        {
            b[i] = a[h];
            h = h+1;
        }
        else
        {
            b[i] = a[j];
            j = j+1;
        }
        i = i+1;
    }

    if(h>mid)
    {
        for(int k=j; k<=high; k++)
        {
            b[i]= a[k];
            i = i+1;
        }
    }
    else
    {
        for(int k=h; k<=mid; k++)
        {
            b[i] = a[k];
            i = i+1;
        }
    }
    for(int k=low; k<= high; k++)
    {
        a[k] = b[k];
    }
}
void MergeSort(int low , int high)
{
    if(low<high)
    {
        int mid = floor( (low+high)/2 );

        MergeSort(low,mid);
        MergeSort(mid+1, high);

        Merge(low, mid, high);
    }
}


int main()
{
    ifstream inFile("number.txt");
    if (inFile.is_open())
    {
        int num;
        while (inFile >> num)
        {
            a.push_back(num);
        }
        inFile.close();
    }
    else
    {
        cerr << "Unable to open file for reading." << endl;
        return 1;
    }

    int n = a.size();
    b.resize(n);
    cout << "Vector Size: " << n << endl;

    // Start timing
    auto start = chrono::high_resolution_clock::now();

    // Execute the function to measure
    MergeSort(0, n - 1);

    // End timing
    auto End = chrono::high_resolution_clock::now();

    // Calculate the duration in nanoseconds
    chrono::duration<double> duration = End - start;

    // Output the time taken in seconds
    cout << "Time taken: " << duration.count() << " seconds" << endl;

    return 0;
}
