#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> &v)
{
    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int memoiz(string &x, string &y, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 or m == 0)
    {
        return 0;
    }
    if (x[n - 1] == y[m - 1])
    {
        if (dp[n - 1][m - 1] == -1)
        {
            dp[n - 1][m - 1] = memoiz(x, y, n - 1, m - 1, dp);
        }
        dp[n][m] = dp[n - 1][m - 1] + 1;
        return dp[n][m];
    }
    else
    {
        int a1 = dp[n - 1][m];
        if (a1 == -1)
        {
            dp[n - 1][m] = memoiz(x, y, n - 1, m, dp);
            a1 = dp[n - 1][m];
        }
        int a2 = dp[n][m - 1];
        if (a2 == -1)
        {
            dp[n][m - 1] = memoiz(x, y, n, m - 1, dp);
            a2 = dp[n][m - 1];
        }
        return dp[n][m] = max(a1, a2);
    }
}

int main()
{
    string x = "abcdgh";
    string y = "abedhfa";
    int n = x.length();
    int m = y.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int ans = memoiz(x, y, n, m, dp);
    display(dp);
    cout << "Ans: " << ans << endl;
    return 0;
}