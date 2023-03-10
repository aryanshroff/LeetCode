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
            if (v[i][j] < 10 and v[i][j] >= 0)
            {
                cout << "0";
            }
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

void mymain(vector<vector<int>> &v)
{
    // for v vector 0 means edge doesnt exist , 1 means there is an edge in given graph
    // direction of propogation=> forward i.e child to parent
    int n = v.size();
    // cout << n << endl;
    vector<int> gold(n, -1);
    gold[n - 1] = 0;
    vector<int> child(n, -1);
    cout << "Given graph" << endl;
    print2d(v);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == 0)
            {
                continue; // edge doesnt exists
            }
            // reached here means v[i][j] is non zero i.e edge exists
            // i is index of current cell and j is index of child cell
            int total = v[i][j] + gold[j];
            if (gold[i] == -1 or gold[i] > total)
            {
                gold[i] = total; // stored the current minimum value
                child[i] = j;    // child of i updated
            }
        }
    }
    // print1d(gold);
    // print1d(child);
    cout << "Minimum cost of the multi staged graph is: " << gold[0] << endl;
    cout << endl;
    cout << "Printing the cheapest Path" << endl;
    vector<int> cheapest;
    int parent_index = 0, child_index = 0;
    while (parent_index != -1)
    {
        cheapest.push_back(parent_index + 1);
        parent_index = child[parent_index];
    }
    print1d(cheapest);
}

int main()
{
    // take all input here
    vector<vector<int>> v = {{0, 9, 7, 3, 2, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 4, 2, 1, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 2, 7, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 11, 8, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 6, 5, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 6, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    // input end
    vector<vector<int>> v2 = {{0, 1, 2, 5, 0, 0, 0, 0},
                              {0, 0, 0, 0, 4, 11, 0, 0},
                              {0, 0, 0, 0, 9, 5, 16, 0},
                              {0, 0, 0, 0, 0, 0, 2, 0},
                              {0, 0, 0, 0, 0, 0, 0, 18},
                              {0, 0, 0, 0, 0, 0, 0, 13},
                              {0, 0, 0, 0, 0, 0, 0, 2},
                              {0, 0, 0, 0, 0, 0, 0, 0}};
    chrono::system_clock::time_point start = high_resolution_clock::now();
    mymain(v1);
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