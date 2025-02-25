#include <bits/stdc++.h>
#include <chrono>

using namespace std;

void Adjust(vector<int>& A, int i, int n)
{
    int j = 2 * i;
    int item = A[i];

    while (j <= n)
    {
        if (j <= n && A[j] > A[j + 1])
            j = j + 1;
        if (item <= A[j])
            break;
        A[j/2] = A[j];
        j = 2 * j;
    }
    A[j/2] = item;
}

void Heapify(vector<int>& A, int n)
{
    for (int i = (n / 2) ; i >= 0; i--)
        Adjust(A, i, n);
}

vector<int> mergeKSortedArrays(vector<vector<int>>& arrays)
{
    vector<int> heap;

    for (const auto& arr : arrays)
    {
        for (int num : arr)
            heap.push_back(num);
    }

    int n = heap.size();
    Heapify(heap, n - 1);

    vector<int> result;
    for (int i = n - 1; i >= 0; i--)
    {
        result.push_back(heap[0]);
        heap[0] = heap[i];
        Adjust(heap, 0, i - 1);
    }
    return result;
}

int main()
{
    vector<vector<int>> arrays = {
        {3, 5, 17, 1},
        {2, 9, 8},
        {7 ,2, 6, 5 }
    };

    vector<int> mergedArray = mergeKSortedArrays(arrays);

    cout << "Merged sorted array: ";
    for (int num : mergedArray)
        cout << num << " ";
    cout << endl;

    return 0;
}
