// Max heap
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

void Adjust(vector<int>& A, int i, int n)
{
    int j = 2 * i ; // Left child index , Adjusted for 0-based index
    int item = A[i]; // Store the current node value

    while (j <= n)
    {
        // If the right child exists and is greater than the left child
        if (j < n && A[j] > A[j + 1])
            j++; // Move to right child
        // If the item is greater than or equal to the largest child, we break
        if (item <= A[j])
            break;

        // Move the child up to the parent
        A[j/2] = A[j];
        // Move down to the child
        j = 2 * j; // Update the child index
    }
    A[j/2] = item; // Place the item at its correct position
}

void Heapify(vector<int>& A, int n)
{
    for (int i = (n / 2) ; i >= 0; i--)
        Adjust(A, i, n);
}

void HeapSort(vector<int>& A, int n)
{
    Heapify(A, n); // Build max-heap

    for (int i = n; i >= 1; i--)
    {
        // Swap the root of the heap (max element) with the last element
        int t = A[i];
        A[i] = A[0];
        A[0] = t;
        Adjust(A, 0, i - 1); // Adjust the heap
    }
}

int main()
{
    // Example patient ages
    vector<int> A = {2, 9, 7, 6, 1, 5, 8, 5, 8, 10, 23};

    cout << "Original ages: ";
    for (int age : A)
        cout << age << " "; // Display original ages
    cout << endl;

    HeapSort(A, A.size() - 1); // Sort the ages

    cout << "Sorted by priority (oldest to youngest): ";
    for (int age : A)
        cout << age << " "; // Display sorted ages
    cout << endl;

    return 0;
}
