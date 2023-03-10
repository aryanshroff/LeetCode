#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

// given an infinte supply of each coin return the number of ways of paying the bill

int memoiz(int sum, vector<int> &coins, int ipas, vector<vector<int>> &dp)
{
    if (sum == 0)
    {
        return 1;
    }
    if (ipas == 0)
    {
        return 0;
    }
    int last = coins[ipas - 1];
    int a1 = dp[ipas - 1][sum];
    if (a1 == -1)
    {
        a1 = memoiz(sum, coins, ipas - 1, dp);
        dp[ipas - 1][sum] = a1;
    }
    if (last > sum)
    {
        dp[ipas][sum] = a1;
        return a1;
    }
    else
    {
        int a2 = dp[ipas][sum - last];
        if (a2 == -1)
        {
            a2 = memoiz(sum - last, coins, ipas, dp);
            dp[ipas][sum - last] = a2;
        }
        dp[ipas][sum] = a1 + a2;
        return a1 + a2;
    }
}

int main()
{
    vector<int> coins = {1, 2, 3, 4, 5, 6, 7};
    int sum = 22;
    int ipas = coins.size();
    vector<vector<int>> dp(ipas + 1, vector<int>(sum + 1, -1));
    cout << " Ways: " << memoiz(sum, coins, ipas, dp) << endl;
    return 0;
}