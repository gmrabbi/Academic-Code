// Min-heap implementation to merge k sorted arrays
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

// Adjust the heap to maintain the min-heap property
void Adjust(vector<int>& A, int i, int n)
{
    int j = 2 * i; // Start with the left child
    int item = A[i];

    while (j <= n)
    {
        if (j <= n && A[j] > A[j + 1]) // Compare with right child
            j = j + 1;
        if (item <= A[j])
            break;
        A[j/2] = A[j];
        // Move down to the child
        j = 2 * j; // Update the child index
    }
    A[j/2] = item; // Place the item at its correct position
}

// Function to heapify the array
void Heapify(vector<int>& A, int n)
{
    for (int i = (n / 2) ; i >= 0; i--)
        Adjust(A, i, n);
}

// Function to merge k sorted arrays
vector<int> mergeKSortedArrays(vector<vector<int>>& arrays)
{
    vector<int> heap;

    // Push the first element of each array into the heap
    for (const auto& arr : arrays)
    {
        for (int num : arr)
            heap.push_back(num);
    }

    int n = heap.size();
    Heapify(heap, n - 1); // Create a min-heap from the elements

    vector<int> result;

    // Extract elements from the min-heap
    for (int i = n - 1; i >= 0; i--)
    {
        result.push_back(heap[0]); // Get the minimum element
        heap[0] = heap[i]; // Move the last element to the root
        Adjust(heap, 0, i - 1); // Adjust the heap
    }
    return result; // Return the merged array
}

int main()
{
    vector<vector<int>> arrays = {
        {1, 4, 17, 10},
        {2, 5, 8},
        {7 ,3, 6, 9 }
    };

    vector<int> mergedArray = mergeKSortedArrays(arrays);

    cout << "Merged sorted array: ";
    for (int num : mergedArray)
        cout << num << " ";
    cout << endl;

    return 0;
}
