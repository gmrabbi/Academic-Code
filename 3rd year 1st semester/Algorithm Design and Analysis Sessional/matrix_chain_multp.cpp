#include <iostream>
#include <vector>
#include <climits>
#include <functional> // Include this header for std::function

using namespace std;

void matrixChainMultiplication(vector<int>& dimensions) {
    int n = dimensions.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> bracket(n + 1, vector<int>(n + 1, 0));

    // Fill dp table for chains of length 2 to n
    for (int length = 2; length <= n; ++length) {
        for (int i = 1; i <= n - length + 1; ++i) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            cout << "\nCalculation for dp[" << i << "][" << j << "]:\n";
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                cout << "Split at k=" << k << ": dp[" << i << "][" << k << "] + dp[" << k + 1 << "][" << j << "] + "
                     << dimensions[i - 1] << "*" << dimensions[k] << "*" << dimensions[j] << " = "
                     << dp[i][k] << " + " << dp[k + 1][j] << " + " << (dimensions[i - 1] * dimensions[k] * dimensions[j])
                     << " = " << (dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j]) << endl;

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    bracket[i][j] = k;
                }
            }
            cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
        }
    }

    // Display the dp table
    cout << "\nDP Table:\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) {
                cout << "  - ";
            } else {
                cout << dp[i][j] << " ";
            }
        }
        cout << endl;
    }

    // Final result
    cout << "\nMinimum number of multiplications required: " << dp[1][n] << endl;

    // Print optimal parenthesis
    cout << "Optimal Parenthesization: ";
    function<void(int, int)> printParenthesis = [&](int i, int j) {
        if (i == j) {
            cout << "A" << i;
            return;
        }
        cout << "(";
        printParenthesis(i, bracket[i][j]);
        printParenthesis(bracket[i][j] + 1, j);
        cout << ")";
    };
    printParenthesis(1, n);
    cout << endl;
}

int main() {
    vector<int> dimensions = {5,4,6,2,7};   // {10, 25, 40, 8, 36, 28};
    matrixChainMultiplication(dimensions);
    return 0;
}
