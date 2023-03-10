#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string convert(string child)
{
    string c;
    bool l = true;
    for (int i = 0; i < child.length(); i++)
    {
        if (l == true and child[i] == '0')
        {
            continue;
        }
        else
        {
            l = false;
            c.push_back(child[i]);
        }
    }
    if (c == "")
    {
        c = '0';
    }
    return c;
}

bool cmp(string child, string parent)
{

    string c = convert(child);
    string p = convert(parent);
    if (p.length() - c.length() > 1)
    {
        return false;
    }
    // leading zeros from both are removed
    long long c1 = stoll(c);
    long long p1 = stoll(p);
    if (c1 == 0 and p1 == 0)
    {
        return true;
    }
    // cout<<c1<<endl;
    // cout<<p1<<endl;
    long long diff = p1 - c1;
    // cout<<diff<<endl;
    if (diff == 1)
    {
        cout << "diff: " << diff << " true returned" << endl;
        return true;
    }
    else
    {
        cout << "false returned" << endl;
        return false;
    }
}

// to generate all substrings from current index and store it in a vector
vector<string> generate(string &s, int index)
{
    vector<string> v;
    string temp = "";
    for (int i = index; i < s.length(); i++)
    {
        temp.push_back(s[i]);
        v.push_back(temp);
    }
    return v;
}

bool dfs(string &s, string parent, int start_index)
{
    if (start_index == s.length())
    {
        cout << " start index:" << start_index << " true from dfs" << endl;
        return true;
    }
    vector<string> v = generate(s, start_index);
    for (int i = 0; i < v.size(); i++)
    {
        string child = v[i];
        int temp = start_index + child.size();
        if (cmp(child, parent) == true)
        {
            return dfs(s, child, temp);
        }
    }
    cout << "line 95 se false returned , we back track" << endl;
    cout << endl;
    return false;
}

bool solve(string s)
{
    cout << "I/p: " << s << endl;
    vector<string> v = generate(s, 0);
    bool ans = false;
    for (int i = 0; i < v.size() - 1; i++)
    {
        string parent = v[i];
        ans = dfs(s, parent, parent.size());
        if (ans == true)
        {
            break;
        }
    }
    cout << "Result for s: " << s << " is: " << ans << endl;
    return ans;
}

void test()
{

    cout << solve("94650723337775781477") << endl;
    cout << solve("504") << endl;
    cout << solve("054") << endl;
    cout << solve("0000500004") << endl;
    cout << solve("5043") << endl;

    cout << solve("540") << endl;
    cout << solve("100200") << endl;
    cout << solve("00") << endl;
    // special case: at string =0 manually return false otherwise dfs will return true
    // use the convert function to remove leading zeros
    // if length of returned string is 1 then use stoi to convert it to integer x
    // if x==0 manually return false
}

int main()
{
    test();
}