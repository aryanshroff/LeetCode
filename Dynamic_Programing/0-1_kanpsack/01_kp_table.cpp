#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> v)
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

// memoization we initialise the table to -1

vector<vector<int>> table(vector<int> c, vector<int> wt, int bag)
{
    // c and w will have same size
    // cols correspond to size of input array
    int col = bag + 1; // wt is available space left in bag

    // row correspond to bag capacity at that particular col value
    // bag capacity ranges from 0 to bag
    int row = c.size() + 1; // n is size of inpit array
    vector<vector<int>> dp(row, vector<int>(col, 0));
    display(dp);
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (wt[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], c[i - 1] + dp[i - 1][j - wt[i - 1]]);
            }
        }
    }

    return dp;
}

int main()
{
    vector<int> c = {1,6,18,22,28};
    vector<int> wt = {1,2,5,6,7};
    int bag = 11;
    vector<vector<int>> v = table(c, wt, bag);
    cout << "Final 2d vector" << endl;
    display(v);
    cout << endl;
    cout << "profit: " << v[v.size() - 1][v[0].size() - 1];
    return 0;
}