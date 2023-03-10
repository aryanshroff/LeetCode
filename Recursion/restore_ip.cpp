#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<string> &v, int n, string &s, string p, int index)
{
    if (index == n)
    {
        v.push_back(p);
    }
    string temp = "";
    p.push_back(s[index]);
    p.push_back('.');
    temp.push_back(s[index]);
    dfs(v, n, s, p, index + 1);
    int n2 = p.length();
    if (p[n2 - 1] != '0')
    {
        p.push_back(s[index + 1]);
        p.push_back('.');
        temp.push_back(s[index + 1]);
        dfs(v, n, s, p, index + 2);

        p.push_back(s[index + 2]);
        p.push_back('.');
        temp.push_back(s[index + 2]);
        if (temp <= "255")
        {
            dfs(v, n, s, p, index + 3);
        }
    }
}

vector<string> solve(string &s)
{
    vector<string> v;
    int n = s.length();
    if (n > 12 or n < 4)
    {
        return v;
    }

    return v;
}

int main()
{
    string s = "25525511135";

    return 0;
}