#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

template <typename T>
void print2d(vector<vector<T>> v)
{
    cout << " 2D VECTOR " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

bool check(int &i, int &j, int &n, vector<bool> &left, vector<bool> &right, vector<bool> &col)
{
    if (left[i + j - 1] == true)
        return false;
    if (right[n - j + i] == true)
        return false;
    if (col[j] == true)
        return false;
    return true;
}
void helper(vector<vector<string>> &ans, vector<string> &curr, int i, int j, int &n, vector<bool> &left, vector<bool> &right, vector<bool> &col)
{
    if (i > n)
    {
        ans.push_back(curr);
        return;
    }
    if (j > n)
    {
        return;
    }
    if (check(i, j, n, left, right, col))
    {
        left[i + j - 1] = true;
        right[n - j + i] = true;
        col[j] = true;
        curr[i - 1][j - 1] = 'Q';
        helper(ans, curr, i + 1, 1, n, left, right, col);
        left[i + j - 1] = false;
        right[n - j + i] = false;
        col[j] = false;
        curr[i - 1][j - 1] = '.';
    }
    helper(ans, curr, i, j + 1, n, left, right, col);
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<bool> left(2 * n, false), right(2 * n, false), col(n + 1, false);
    string str = "";
    for (int i = 0; i < n; i++)
        str += '.';
    vector<string> curr(n, str);
    helper(ans, curr, 1, 1, n, left, right, col);
    return ans;
}

void mymain(int n)
{

    vector<vector<string>> ans = solveNQueens(n);
    print2d(ans);
}

int main()
{
    // take all input here
    int n;
    cout << "Enter board dimensions: " << endl;
    cin >> n;

    // input end
    chrono::system_clock::time_point start = high_resolution_clock::now();
    mymain(n);
    chrono::system_clock::time_point stop = high_resolution_clock::now();
    chrono::milliseconds duration = duration_cast<milliseconds>(stop - start);

    double time = duration.count();
    string unit = "ms";
    if (time >= 1000 and time < 60000)
    {
        time = time / 1000;
        unit = "sec";
    }
    cout << endl;
    cout << endl;
    cout << "Code Execution Time: " << time << " " << unit << endl;
    return 0;
}