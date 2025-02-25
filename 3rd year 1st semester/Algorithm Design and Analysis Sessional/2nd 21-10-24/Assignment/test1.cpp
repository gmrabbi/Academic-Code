// Min heap
#include <bits/stdc++.h>
using namespace std;

void Adjust(vector<int>& A, int i, int n)
{
    int j = 2 * i + 1;
    int item = A[i];

    while (j < n)
    {

        if ((j + 1 < n) && (A[j] > A[j + 1]))
            j = j + 1;
        if (item <= A[j])
            break;
        A[(j - 1) / 2] = A[j];
        j = 2 * j + 1;
    }
    A[(j - 1) / 2] = item;
}

void Heapify(vector<int>& A, int n)
{
    for (int i = (n - 1) / 2; i >= 0; i--)
        Adjust(A, i, n);
}

void insertKthLargest(vector<int>& minHeap, int num, int k)
{
    if (minHeap.size() < k)
    {
        minHeap.push_back(num);
        Heapify(minHeap, minHeap.size());
    }
    else if (num > minHeap[0])
    {
        minHeap[0] = num;
        Adjust(minHeap, 0, k);
    }
}

int main()
{
    int k = 4;
    vector<int> minHeap;

    vector<int> stream = {10, 11, 75, 57, 42, 95};

    cout << "Processing stream:" << endl;
    for (int num : stream) {
        insertKthLargest(minHeap, num, k);
        if (minHeap.size() == k)
            cout << "inserting " << num << ", " << k << "-th largest so far is " << minHeap[0] << endl;
        else
            cout << "ERROR, inserting " << num << ", less than " << k << " elements in stream." << endl;
    }

    return 0;
}
