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

// return the min number of coins possible to pay the bill

int memoiz(vector<int> &coins, int bill, int ipas, vector<vector<int>> &dp)
{
    if (bill == 0)
    {
        dp[ipas][bill] = 1;
        return 1;
    }
    if (coins.size() == 0)
    {
        dp[ipas][bill] = 0;
        return 0;
    }
    int last = coins[ipas - 1];
    int way1 = dp[ipas - 1][bill];
    cout << last << endl;
    if (way1 == -1)
    {
        way1 = memoiz(coins, bill, ipas - 1, dp);
        dp[ipas - 1][bill] = way1;
    }
    if (last > bill)
    {
        // 2nd branch not possible current ranch is answer
        if (way1 == 0)
        {
            dp[ipas][bill] = 0;
            return 0;
        }
        else
        {
            dp[ipas][bill] = 0;
            return way1 + 1;
        }
    }
    else
    {
        // last coin is usable to bill payment
        int way2 = dp[ipas][bill - last];
        if (way2 == -1)
        {
            way2 = memoiz(coins, bill - last, ipas, dp);
            dp[ipas][bill - last] = way2;
        }

        if (way1 == 0 and way2 == 0)
        {

            dp[ipas][bill] = 0;
            return 0;
        }
        else if (way2 == 0)
        {

            dp[ipas][bill] = way1;
            return way1;
        }
        else if (way1 == 0)
        {

            dp[ipas][bill] = way2;
            return way2 + 1;
        }
        else
        {
            // both are non zero
            if (way1 < way2)
            {
                dp[ipas][bill] = way1;
                return way1;
            }
            else
            {
                dp[ipas][bill] = way2;
                return way2 + 1;
            }
        }
    }
}

int main()
{
    vector<int> coins = {1, 2, 3, 4, 5, 6, 7, 8};
    int bill = 244;
    int ipas = coins.size();
    vector<vector<int>> dp(ipas + 1, vector<int>(bill + 1, -1));
    int ans = memoiz(coins, bill, ipas, dp);
    display(dp);
    cout << "Ans: " << ans;
    return 0;
}