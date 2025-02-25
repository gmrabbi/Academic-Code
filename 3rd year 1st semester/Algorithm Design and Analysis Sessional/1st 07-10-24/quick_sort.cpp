#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <chrono>

using namespace std;


void Interchange(vector<int>& a, int i, int j)
{
    int p = a[i];
    a[i] = a[j];
    a[j] = p;
}

/*
int partition(vector<int>& a, int m, int p)
{
    int v = a[m]; // Pivot element
    int i = m ; // Start from the next element
    int j = p;

    while (i<=j)
    {
        while (a[i] <= v)
        { i++; }

        while (a[j] > v)
        {  j--; }

        // If i is greater than or equal to j, the partition is done
        if (i < j)
        { Interchange(a, i, j); }
    }

    a[m] = a[j];
    a[j] = v;

    return j;
}
*/
int partition(vector<int>& a, int p, int q)
{
    int x = a[q];
    int i = p-1;
    for(int j=p; j<=q-1; j++)
    {
        if(a[j]<=x)
        {
            i++;
            swap(a[j], a[i]);
            for(auto i: a)
                cout<<i<<" ";
            cout<<" ----"<<endl;
        }
    }
    swap(a[q], a[i+1]);
    for(auto i: a)
        cout<<i<<" ";
    cout<<" ----"<<endl;
    return i+1;
}

vector<int> a = {6,10,13,5,8,3,2,11};

void QuickSort(int p, int q)
{
    if (p < q)
    {
        int j = partition(a, p, q);
        /*
        for(auto i: a)
            cout<<i<<" ";
        cout<<endl;

        */QuickSort(p, j - 1);
        QuickSort(j + 1, q);
    }
}

int main()
{

    // Read the numbers back from the file
    /*
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
    */

    int n = a.size();
    cout << "Vector Size: " << n << endl;

    for(auto i: a)
        cout<<i<<" ";
    cout<<endl;

    // Start timing
    auto start = chrono::high_resolution_clock::now();

    // Execute the function to measure
    QuickSort(0, n - 1);

    // End timing
    auto End = chrono::high_resolution_clock::now();

    // Calculate the duration
    chrono::duration<double> duration = End - start;

    // Output the time taken in seconds
    cout << "Time taken: " << duration.count() << " seconds" << endl;

    for(auto i: a)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}
