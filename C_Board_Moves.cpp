#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print1d(vector<T> v)
{
    cout << " 1D VECTOR " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << endl;
}

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

template <typename T>
void printstack(stack<T> s)
{
    cout << " STACK " << endl;
    while (s.empty() == false)
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
    cout << endl;
}

template <typename T>
void printq(queue<T> q)
{
    cout << " QUEUE " << endl;
    while (q.empty() == false)
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    cout << endl;
}

template <class K, class V>
void printhash(unordered_map<K, V> h)
{
    cout << " HASHMAP " << endl;
    for (auto it = h.begin(); it != h.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;
    cout << endl;
}

void solve(int n)
{
    vector<vector<long>> dp(n, vector<long>(3, -1));
    dp[0][0] = 8;
    dp[1][0] = 1;
    dp[2][0] = 8;
    print2d(dp);
    int limit = (n - 1) / 2;
    int i = 1;
    while (i <= limit)
    {
        dp[0][i] = dp[0][i - 1] + 8;
        dp[1][i] = dp[1][i - 1] + 1;
        dp[2][i] = dp[2][i - 1] + (dp[1][i] * dp[0][i]);
        i++;
    }
    cout << dp[2][limit] << endl;
}

void base(int n)
{
    int t, n;
    cin >> t;
    while (t > 0)
    {
        cin >> n;

        solve(n);
        t--;
    }
}

int main()
{
    solve(5);
    cout<<"hello world"<<endl;
    return 0;
}
