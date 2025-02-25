// knapnsap problem for max profit
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 6, m = 15;
    int p[n+1] = {0, 60, 50, 70, 80,30,20};
    int wt[n+1] = {0, 5,3,4,6,2,1};
    int k[n+1][m+1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= m; w++)
        {
            if (i == 0 || w == 0)
                k[i][w] = 0;
            else if (wt[i] <= w)
                k[i][w] = max(p[i] + k[i-1][w-wt[i]], k[i-1][w]);
            else
                k[i][w] = k[i-1][w];
        }
    }

    int maxProfit = k[n][m];
    cout << "Maximum Profit: " << maxProfit << endl;

    int w = m;
    vector<int> includedItems;


    for (int i = n; i > 0 && w > 0; i--)
    {
        if (k[i][w] != k[i-1][w])
        {
            includedItems.push_back(i);
            w -= wt[i];
        }
    }

    cout << "Included Items: ";
    reverse(includedItems.begin(), includedItems.end());
    for (int item : includedItems)
    {
        cout << item << " ";
    }
    cout << endl;

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
