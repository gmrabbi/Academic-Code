#include <iostream>
using namespace std;

// Function to swap the values of two arrays using pointers
void swapArrays(int* arr1, int* arr2, int size) {
    for (int i = 0; i < size; i++) {
        int temp = *(arr1 + i);
        *(arr1 + i) = *(arr2 + i);
        *(arr2 + i) = temp;
    }
}

// Function to print the elements of an array
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int main() {
    const int size = 5;
    int arr1[size] = {1, 2, 3, 4, 5};
    int arr2[size] = {6, 7, 8, 9, 10};

    cout << "Before swapping:" << endl;
    cout << "Array 1: ";
    printArray(arr1, size);
    cout << "Array 2: ";
    printArray(arr2, size);

    // Call the swapArrays function to swap the values of the arrays using pointers
    swapArrays(arr1, arr2, size);

    cout << "After swapping:" << endl;
    cout << "Array 1: ";
    printArray(arr1, size);
    cout << "Array 2: ";
    printArray(arr2, size);

    return 0;
}
