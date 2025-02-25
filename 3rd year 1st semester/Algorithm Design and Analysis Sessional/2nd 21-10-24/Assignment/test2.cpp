// Max heap
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

void Adjust(vector<int>& A, int i, int n) {
    int j = 2 * i ;
    int item = A[i];

    while (j <= n)
    {
        if (j < n && A[j] > A[j + 1])
        {
            j = j+1;
        }
        if (item <= A[j]) {
            break;
        }

        A[j/2] = A[j];
        j = 2 * j;
    }
    A[j/2] = item;
}

void Heapify(vector<int>& A, int n) {
    for (int i = (n / 2) ; i >= 0; i--) {
        Adjust(A, i, n);
    }
}

void HeapSort(vector<int>& A, int n) {
    Heapify(A, n);

    for (int i = n; i >= 1; i--)
    {
        int t = A[i];
        A[i] = A[0];
        A[0] = t;
        Adjust(A, 0, i - 1);
    }
}

int main() {
    vector<int> A = {20, 9, 7, 16, 1, 7, 8, 15, 8, 11, 23};

    cout << "Original ages: ";
    for (int age : A) {
        cout << age << " ";
    }
    cout << endl;

    HeapSort(A, A.size() - 1);

    cout << "Sorted by priority (oldest to youngest): ";
    for (int age : A) {
        cout << age << " ";
    }
    cout << endl;

    return 0;
}
