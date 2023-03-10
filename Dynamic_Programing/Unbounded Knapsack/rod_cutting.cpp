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

int un_kp(vector<int> price, vector<int> length,
          int Max_len, int n, vector<vector<int>> &t)
{

    // The maximum price will be zero,
    // when either the length of the rod
    // is zero or price is zero.
    if (n == 0 || Max_len == 0)
    {
        return 0;
    }

    // If the length of the rod is less
    // than the maximum length, Max_lene will
    // consider it.Now depending
    // upon the profit,
    // either Max_lene  we will take
    // it or discard it.
    if (length[n - 1] <= Max_len)
    {
        t[n][Max_len] = max(price[n - 1] + un_kp(price, length,
                                                 Max_len - length[n - 1], n, t),
                            un_kp(price, length, Max_len, n - 1, t));
    }

    // If the length of the rod is
    // greater than the permitted size,
    // Max_len we will  not consider it.
    else
    {
        t[n][Max_len] = un_kp(price, length,
                              Max_len, n - 1, t);
    }

    // Max_lene Max_lenill return the maximum
    // value obtained, Max_lenhich is present
    // at the nth roMax_len and Max_length column.
    return t[n][Max_len];
}

int memoiz(vector<int> &prize, vector<int> &length, int Max_len, int ipas, vector<vector<int>> &dp)
{
    if (ipas == 0 or Max_len == 0)
    {
        return 0;
    }
    else
    {
        int cost = prize[ipas - 1];
        int len = length[ipas - 1];
        if (len > Max_len)
        {
            // we cantmake the cut , remove last element
            int a1 = dp[ipas - 1][Max_len];
            if (a1 == -1)
            {
                a1 = memoiz(prize, length, Max_len, ipas - 1, dp);
                dp[ipas - 1][Max_len] = a1;
            }
            dp[ipas][Max_len] = a1;
            return a1;
        }
        else
        {
            // we can make the cut
            int a1 = dp[ipas - 1][Max_len];
            if (a1 == -1)
            {
                a1 = memoiz(prize, length, Max_len, ipas - 1, dp);
                dp[ipas - 1][Max_len] = a1;
            }

            int a2 = dp[ipas][Max_len - len];
            if (a2 == -1)
            {
                a2 = memoiz(prize, length, Max_len - len, ipas, dp);
                dp[ipas][Max_len - len] = a2;
            }
            int final = max(a2 + cost, a1);
            dp[ipas][Max_len] = final;
            return final;
        }
    }
}



int main()
{
    vector<int> prize = {1, 5, 8, 9, 10, 17, 17, 20};
    vector<int> length;
    int ipas = prize.size();
    for (int i = 0; i < ipas; i++)
    {
        length.push_back(i + 1);
    }
    int Max_len = ipas;
    vector<vector<int>> dp(ipas + 1, vector<int>(Max_len + 1, -1));
    // display(dp);
    int ans = memoiz(prize, length, Max_len, ipas, dp);
    // display(dp);
    cout << "ANS: " << ans<<endl;
    vector<vector<int>> t(ipas + 1, vector<int>(Max_len + 1, -1));
    int test = un_kp(prize, length, Max_len, ipas, t);
    cout<<"Test: "<<test;
}