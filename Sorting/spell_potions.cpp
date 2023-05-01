#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

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

vector<int> successfulPairs(vector<int> &spell, vector<int> &potion, long long product)

{
    // hahmap of spell and index
    unordered_map<int, int> h;
    for (int i = 0; i < spell.size(); i++)
    {
        h[spell[i]] = i;
    }
    sort(spell.begin(), spell.end());
    sort(potion.rbegin(), potion.rend());
    printhash(h);
    print1d(spell);
    print1d(potion);
    int n=spell.size();
    vector<int> res(n,0);;
    int pwc = 0, pfi = 0;
    for (int i = 0; i < spell.size(); i++)
    {
        while (pfi < potion.size())
        {
            if (spell[i] * potion[pfi] >= product)
            {
                pwc++;
                pfi++;
            }
            else{
                int target=h[]
            }
        }
    }
    return res;
}

int main()
{
    // take all input here
    vector<int> v1 = {5, 1, 3};
    vector<int> v2 = {1, 2, 3, 4, 5};
    // input end
    chrono::system_clock::time_point start = high_resolution_clock::now();
    successfulPairs(v1, v2, 7);
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