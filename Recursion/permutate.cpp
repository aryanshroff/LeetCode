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

void permutate(vector<vector<int>> &res, vector<int> &ipv, vector<int> opv,vector<bool> indices)
{
    if (opv.size() == ipv.size())
    {
        res.push_back(opv);
    }
    for(int i=0;i<ipv.size();i++){
        if(indices[i]==true){
            continue;
        }
        int curr=ipv[i];
        indices[i]=true;
        opv.push_back(curr);
        permutate(res,ipv,opv,indices);
        opv.pop_back();
        indices[i]=false;
    }

    
}

int main()
{
    vector<int> ipv = {1, 2, 2};
    int n = ipv.size();
    vector<vector<int>> res;
    vector<int> opv;
    vector<bool> indices(n,false);
    permutate(res,ipv,opv,indices);
    print2d(res);
    return 0;
}