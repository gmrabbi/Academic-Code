#include <bits/stdc++.h>
#include <chrono>

using namespace std;

void Heapify(vector<int>& A, int n, int i)
{
    int L = 2*i+1;
    int R = 2*i+2;
    int large = i;
    if(L<n && A[L]>A[i])
        large = L;
    if(R<n && A[R]>A[large])
        large = R;
    if(large != i)
    {
        swap(A[i], A[large]);
        Heapify(A, n, large);
    }
}

void BuildHeap(vector<int>& A, int n)
{
    for(int i=(n/2)-1; i>=0; i--)
        Heapify(A,n,i);
}

void HeapSort(vector<int>& A, int n)
{
    BuildHeap(A, n);
    for(int i=n-1; i>=0; i--)
    {
        swap(A[0], A[i]);
        Heapify(A,i, 0);
    }
}

int main()
{
    vector<int> A;

    ifstream infile("number.txt");
    int num;
    if(infile.is_open())
    {
        while(infile>>num)
        {
            A.push_back(num);
        }
        infile.close();
    }
    else
    {
        cout<<"Unable to access file"<<endl;
        return -1;
    }
    cout<<endl;

    int n = A.size();

    auto start = chrono::high_resolution_clock::now();
    HeapSort(A, n);
    auto End = chrono::high_resolution_clock::now();

    chrono::duration<double, std::milli> duration = End - start;

    cout << "Total time taken: " << duration.count() << " milliseconds." << endl;


    for(int i=0; i<n; i++)
        cout<<A[i]<<" ";
    cout<<endl;

    return 0;
}
