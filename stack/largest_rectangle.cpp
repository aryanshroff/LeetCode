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

vector<int> left_smaller(vector<int> &v)
{
    stack<pair<int, int>> s;
    vector<int> ans;
    for (int i = 0; i < v.size(); i++)
    {

        while (s.empty() == false and s.top().first > v[i])
        {
            s.pop();
        }
        if (s.empty() == true)
        {
            ans.push_back(-1);
        }
        else
        {
            // top is the answer
            ans.push_back(s.top().second);
        }
        s.push({v[i], i});
    }
    return ans;
}

vector<int> right_smaller(vector<int> &v)
{
    stack<pair<int, int>> s; // number,index
    int n = v.size();
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {

        while (s.empty() == false and s.top().first > v[i])
        {
            s.pop();
        }
        if (s.empty() == true)
        {

            ans.push_back(-1);
        }
        else
        {
            // top is the answer

            ans.push_back(s.top().second);
        }
        s.push({v[i], i});
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int solve(vector<int> &lhs, vector<int> &rhs, vector<int> &v)
{
    int area = -1;
    for (int i = 0; i < v.size(); i++)
    {
        // find distance from current position to left boundary
        int left_distance = 1;
        if (lhs[i] != -1)
        {
            left_distance = i - lhs[i];
            
        }
        // find distance from current position to right boundary
        int right_distance = 1;
        if (rhs[i] != -1)
        {
            right_distance = rhs[i] - i;
            
        }
        // find total distance
        int total=(left_distance+right_distance);
        // area=total distance* val at current index
        int val=total*v[i];
        area=max(area,val);
    }
    return area;
}

int main()
{
    vector<int> v = {2,6};
    print1d(v);
    vector<int> lhs = left_smaller(v);
    print1d(lhs);
    vector<int> rhs = right_smaller(v);
    print1d(rhs);
    cout<<"area: "<<solve(lhs,rhs,v)<<endl;

    return 0;
}