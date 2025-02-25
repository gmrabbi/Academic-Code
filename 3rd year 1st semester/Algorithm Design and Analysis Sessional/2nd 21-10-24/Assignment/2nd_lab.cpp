#include <bits/stdc++.h>
#include <chrono>

using namespace std;

void Adjust(vector<int>& A, int i, int n)
{
    int j = 2*i;
    int item = A[i];

    while(j<=n)
    {
        if( (j<n) && (A[j]<A[j+1]) )
            j = j+1;
        if(item>=A[j])
            break;
        A[j/2] = A[j];
        j = 2*j;
    }
    A[j/2] = item;
}

void Heapify(vector<int>&A, int n)
{
    for(int i=floor((n/2))-1; i>=0; i--)
    {
        Adjust(A, i, n);
    }
}

void HeapSort(vector<int>& A, int n)
{
    Heapify(A,n);

    for(int i=n; i>=1; i--)
    {
        int t = A[i];
        A[i] = A[0];
        A[0] = t;

        Adjust(A, 0, i-1);
    }
}

int main()
{
    vector<int> A ; // = {2,9,7,6,5,8};

    // random data
    // /*
    ifstream inFile("number.txt");

    int num;
    while(inFile>>num)
        A.push_back(num);
    inFile.close();

    // /*
    for(int i=0; i<A.size(); i++)
        cout<<A[i]<<" ";
    cout<<endl;
    // */


    // Asc order
    /*
    int randNum = 1000000;
    for(int i=1; i<=randNum; i++)
    {
        // cout<<i<<endl;
        A.push_back(i);
    }
    */

    // Desc order
    /*
    int randNum = 100000;
    for(int i=randNum; i>0; i--)
    {
        // cout<<i<<endl;
        A.push_back(i);
    }
    */


    // auto start = chrono::high_resolution_clock::now();
    HeapSort(A, A.size()-1);
    // auto End = chrono::high_resolution_clock::now();

    // Calculate the duration
    // chrono::duration<double, std::milli> duration = End - start;

    // Output the time taken in seconds
    // cout << "Time taken: " << duration.count() << " millisecond" << endl;


    // /*
    for(int i=0; i<A.size(); i++)
        cout<<A[i]<<" ";
    cout<<endl;
    // */


    return 0;
}


