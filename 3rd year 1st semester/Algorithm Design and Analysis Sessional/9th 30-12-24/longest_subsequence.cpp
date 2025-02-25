#include <bits/stdc++.h>

using namespace std;

// Function to find LCS recursively
int LCS(int i, int j, const string& a, const string& b) {
    // Base case: if either string is exhausted
    if (i == a.length() || j == b.length()) {
        return 0;
    }
    // If characters match, move both indices forward
    if (a[i] == b[j]) {
        return 1 + LCS(i + 1, j + 1, a, b);
    }
    // If characters don't match, explore both possibilities (skip one character from either string)
    else {
        return max(LCS(i + 1, j, a, b), LCS(i, j + 1, a, b));
    }
}

int main() {
    string a = "AGGTAB";
    string b = "GXTXAYB";

    // Call LCS function starting from the first characters of both strings
    int result = LCS(0, 0, a, b);

    cout << "Length of LCS is " << result << endl;

    return 0;
}
