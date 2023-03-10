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

int solve(string start, string end, vector<string> v, int n)
{
    unordered_map<string, string> h;
    for (int i = 0; i < v.size(); i++)
    {
        string s = v[i];
        cout << "at s:" << s << endl;
        for (int j = 0; j < n; j++)
        {
            string s1 = s.substr(0, j);
            string s2 = s.substr(j + 1, n - j);
            string res = s1 + '*' + s2;
            cout << "res generated: " << res << endl;
            h[res] = s;
        }
        cout << endl;
    }
    printhash(h);
    cout << "wordlist size:" << v.size() << " Hashset size: " << h.size() << endl;
    int level = 0;
    queue<string> q;
    q.push(start);
    q.push("-1");
    unordered_set<string> visited;
    while (q.size() > 1)
    {
        string s = q.front();
        q.pop();

        if (s == "-1")
        {
            q.push(s);
            level++;
            continue;
        }
        visited.insert(s);
        for (int j = 0; j < n; j++)
        {
            string s1 = s.substr(0, j);
            string s2 = s.substr(j + 1, n - j);
            string res = s1 + '*' + s2;

            auto it = h.find(res);
            if (it != h.end())
            {
                string next = it->second;

                auto it2 = visited.find(next);
                if (it2 != visited.end())
                {
                    // match is true
                    continue;
                }
                cout << "parent: " << s << " child: " << next << " acro:" << res << endl;
                if (next == end)
                {
                    cout << "line 124" << endl;
                    break;
                }
                q.push(next);
            }
        }
    }
    return level;
}

int main()
{
    vector<string> v{"hit", "hot", "log", "dot", "lot", "dog", "cog"};
    cout << solve("hit", "cog", v, 3);

    return 0;
}