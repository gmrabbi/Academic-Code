// knapnsap problem for max profit
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 6, m = 15;  // s: max items; n: items to consider; m: max capacity

    int p[n+1] = {0, 60, 50, 70, 80,30,20};   // Profits (1-based indexing)
    int wt[n+1] = {0, 5,3,4,6,2,1};  // Weights (1-based indexing)
    int k[n+1][m+1];                // DP table

    // Build DP table
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= m; w++)
        {
            if (i == 0 || w == 0)
                k[i][w] = 0;  // Base case
            else if (wt[i] <= w)
                k[i][w] = max(p[i] + k[i-1][w-wt[i]], k[i-1][w]);  // Include or exclude
            else
                k[i][w] = k[i-1][w];  // Exclude
        }
    }

    // Find maximum profit
    int maxProfit = k[n][m];
    cout << "Maximum Profit: " << maxProfit << endl;

    // Backtrack to find included items
    int w = m;  // Start with full weight capacity
    vector<int> includedItems;

    for (int i = n; i > 0 && w > 0; i--)
    {
        if (k[i][w] != k[i-1][w])    // Item i was included
        {
            includedItems.push_back(i);  // Store item index
            w -= wt[i];  // Reduce remaining weight
        }
    }

    // Output included items
    cout << "Included Items: ";
    reverse(includedItems.begin(), includedItems.end());
    for (int item : includedItems)
    {
        cout << item << " ";
    }
    cout << endl;

    // Print DP table (optional)
    cout << "\nDP Table:\n";
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= m; w++)
        {
            cout << k[i][w] << " ";
        }
        cout << endl;
    }

    return 0;
}
