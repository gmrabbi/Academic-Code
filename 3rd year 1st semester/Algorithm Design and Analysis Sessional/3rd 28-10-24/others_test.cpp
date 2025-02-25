#include <iostream>
#include <vector>
#include <chrono> // Include for timing
using namespace std;

void SumOfSub(int s, int k, int r, const vector<int>& w, vector<int>& x, int m) {
    if (s == m) {
        cout << "Subset found: { ";
        for (int i = 1; i < w.size(); ++i) {
            if (x[i] == 1) {
                cout << w[i] << " ";
            }
        }
        cout << "}" << endl;
        return;
    }

    // Including the current element in the subset
    if (s + w[k] <= m) {
        x[k] = 1;
        SumOfSub(s + w[k], k + 1, r - w[k], w, x, m);
    }

    // Not including the current element in the subset
    if (s + r - w[k] >= m) {
        x[k] = 0;
        SumOfSub(s, k + 1, r - w[k], w, x, m);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> w(n + 1);
    cout << "Enter the elements: ";
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }

    int m;
    cout << "Enter the sum: ";
    cin >> m;

    vector<int> x(n + 1, 0);
    int r = 0;

    // Calculate the total sum of the elements
    for (int i = 1; i <= n; ++i) {
        r += w[i];
    }

    // Start timing
    auto start = chrono::high_resolution_clock::now();

    // Call the recursive function
    SumOfSub(0, 1, r, w, x, m);

    // End timing
    auto end = chrono::high_resolution_clock::now();

    // Calculate and print the elapsed time
    chrono::duration<double, std::milli> elapsed = end - start;
    cout << "Time taken: " << elapsed.count() << " ms" << endl;

    return 0;
}
