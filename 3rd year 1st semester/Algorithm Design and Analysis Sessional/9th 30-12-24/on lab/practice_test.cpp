#include <bits/stdc++.h>

using namespace std;

string Find_LCS(string a, string b)
{
    int n = a.length(), m = b.length();

    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i-1]==b[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    string lcs="";
    int i=n, j=m;
    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            lcs += a[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    reverse(lcs.begin(), lcs.end());

    return lcs;
}

int main()
{
    string str1 = "lullabybabies";
    string str2 = "skullandbones";

    string str = Find_LCS(str1, str2);
    cout<<str<<endl;
    cout<<str.length()<<endl;
    return 0;
}
