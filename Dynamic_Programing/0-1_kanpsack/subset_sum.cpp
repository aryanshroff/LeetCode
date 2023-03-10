#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// return the colunt of subsets that have a given sum =t via memoisation

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
    cout << endl;
    cout << endl;
    cout << endl;
}
int test = 0;

int memois(vector<int> &v, int k, int ipas, vector<vector<int>> &dp)
{
    if (k == 0)
    {
        return 1;
    }
    if (ipas == 0)
    {
        return 0;
    }
    int curr = v[ipas - 1];
    int a1 = dp[ipas - 1][k];
    if (a1 == test)
    {
        a1 = memois(v, k, ipas - 1, dp);
        dp[ipas - 1][k] = a1;
    }

    if (curr > k)
    {
        dp[ipas][k] = a1;
        return a1;
    }
    else
    {
        int a2 = dp[ipas - 1][k - curr];
        if (a2 == test)
        {
            a2 = memois(v, k - curr, ipas - 1, dp);
            dp[ipas - 1][k - curr] = a2;
        }
        dp[ipas][k] = a1 + a2;
        return a1 + a2;
    }
}

int table(vector<int> &v, int k, vector<vector<int>> &dp)
{
    // initialisation
    for (int i = 0; i < dp.size(); i++)
    {
        dp[i][0] = 1;
    }
    cout << "Iniatlised tabulation Matrix" << endl;
    display(dp);
    // table filling
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[i].size(); j++)
        {
            int curr = v[i - 1];
            if (j - curr < 0)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - curr];
            }
        }
    }
    cout << "Tabulation Matrix" << endl;
    display(dp);
    return dp[dp.size() - 1][dp[0].size() - 1];
}

int CountSubsetSum(vector<int> &arr, int val, int n)
{
    int count = 0;
    vector<int> PresentState(val + 1, 0),
        LastState(val + 1, 0);
    // consider only last and present state we dont need the
    // (present-2)th state and above and we know for val to
    // be 0 if we dont pick the current index element we can
    // achieve
    PresentState[0] = LastState[0] = 1;
    if (arr[0] <= val)
        LastState[arr[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= val; j++)
            PresentState[j] = ((j >= arr[i]) ? LastState[j - arr[i]]
                                             : 0) +
                              LastState[j];
        // this we will need in the next iteration so just
        // swap current and last state.
        LastState = PresentState;
    }
    // Note after exit from loop we will having a present
    // state which is nothing but the laststate itself;
    return PresentState[val]; // or return
                              // CurrentState[val];
}

int main()
{
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0};
    sort(v.rbegin(), v.rend());
    int k = 10;
    int row = v.size() + 1;
    int col = k + 1;
    vector<vector<int>> dp(row, vector<int>(col, test));
    int count = memois(v, k, v.size(), dp);
    cout << "Memoisation matrix" << endl;
    display(dp);

    vector<vector<int>> dp2(row, vector<int>(col, test));
    count = table(v, k, dp2);
    cout << "Answer via tabulation is:   " << count << endl;
    cout << "\nAnswer via memoisation is: " << count << endl;
    count = CountSubsetSum(v, k, v.size());
    cout << "Answer from tester code:    " << count << endl;
    return 0;
}