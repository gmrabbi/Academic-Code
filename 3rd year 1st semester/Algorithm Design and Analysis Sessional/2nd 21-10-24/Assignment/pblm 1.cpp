// Min heap
#include <bits/stdc++.h>
using namespace std;

void Adjust(vector<int>& A, int i, int n)
{
    int j = 2 * i + 1;  // Left child index , Adjusted for 0-based index
    int item = A[i];  // Store the current node value

    while (j < n)
    {
        // If the right child exists and is greater than the left child
        if ((j + 1 < n) && (A[j] > A[j + 1])) // Compare with right child
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

// Function to insert into a min-heap of fixed size k
void insertKthLargest(vector<int>& minHeap, int num, int k)
{
    // If the heap has fewer than k elements, just add the new element
    if (minHeap.size() < k)
    {
        minHeap.push_back(num);
        Heapify(minHeap, minHeap.size());
    }
    // If the heap already has k elements, check if the new number should replace the root
    else if (num > minHeap[0])
    {
        minHeap[0] = num;  // Replace root with new element
        Adjust(minHeap, 0, k);  // Re-adjust heap to maintain min-heap property
    }
}

int main()
{
    int k = 3; // Example: Finding the 3rd largest element
    vector<int> minHeap; // Min-heap to store k largest elements

    vector<int> stream = {10, 20, 11, 70, 50, 40, 90}; // Example stream

    cout << "Processing stream:" << endl;
    for (int num : stream) {
        insertKthLargest(minHeap, num, k);
        if (minHeap.size() == k)
            cout << "After inserting " << num << ", " << k << "-th largest so far is " << minHeap[0] << endl;
        else
            cout << "After inserting " << num << ", less than " << k << " elements in stream." << endl;
    }

    return 0;
}
