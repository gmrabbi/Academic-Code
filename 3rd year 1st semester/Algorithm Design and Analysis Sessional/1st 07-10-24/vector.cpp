#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <string>

using namespace std;
int main()
{
    vector<int> arr ; //= {10, 7, 8, 9, 1, 5};
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(9);

    int n = arr.size();

    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quicksort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}
