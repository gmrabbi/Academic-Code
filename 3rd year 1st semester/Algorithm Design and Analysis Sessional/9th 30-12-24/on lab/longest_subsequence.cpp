#include <bits/stdc++.h>

using namespace std;


int LCS(int i, int j, const string& a, const string& b)
{
    if(i==a.length() || j==b.length())
        return 0;
    if(a[i]==b[j])
        return 1+LCS(i+1, j+1, a,b);
    else
        return max(LCS(i+1, j, a,b), LCS(i, j+1, a,b));
}

int main()
{

    string str1 = "lullabybabies";
    string str2 = "skullandbones";

    int result = LCS(0,0,str1, str2);
    cout<<"length : "<<result<<endl;

    return 0;
}
