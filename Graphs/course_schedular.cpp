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

bool solve(int n, vector<vector<int>> &p)
{
    // generate 2d
    vector<vector<int>> graph(n, vector<int>(n, 0));
    unordered_map<int, int> indegree;
    for (int i = 0; i < n; i++)
    {
        indegree[i] = 0;
    }
    for (int i = 0; i < p.size(); i++)
    {
        int c = p[i][1];
        int r = p[i][0];
        graph[r][c]++;
        // indegree of col increases by 1
        indegree[c]++;
    }
    queue<int> node_with_0_indegree;
    // now i know how many indegrees each node has
    for (auto it = indegree.begin(); it != indegree.end(); it++)
    {
        if (it->second == 0)
        {
            node_with_0_indegree.push(it->first);
        }
    }
    // keep on working untill the queue becomes empty
    int jobs_done = 0;
    while (node_with_0_indegree.empty() == false)
    {
        int node = node_with_0_indegree.front();
        node_with_0_indegree.pop();
        jobs_done++;
        for (int i = 0; i < n; i++)
        {
            if (graph[node][i] != 0)
            {
                graph[node][i]--; // erased the edge
                indegree[i] -= 1;
                if (indegree[i] == 0)
                {
                    // i has become a node with 0 indegree
                    node_with_0_indegree.push(i);
                }
            }
        }
    }
    // all the 0 indegree nodes have been taken care of
    if (jobs_done != n)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int num = 5;
    vector<vector<int>> p = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {3, 4}, {4, 2}, {2, 1}};
    print2d(p);
    cout << boolalpha << endl;
    cout << "returned value: " << solve(num, p);
    return 0;
}