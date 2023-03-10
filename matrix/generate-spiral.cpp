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

void get_status(int i, int row, int col, int row_start, int row_end, int col_start, int col_end, int index)
{
    cout << "i:" << i << "     row_start:" << row_start << "   row_end:" << row_end << "      col_start:" << col_start << "   col_end:" << col_end << "   index:" << index << endl;
}

vector<vector<int>> solve(vector<int> &v, int row, int col)
{
    vector<vector<int>> mat(row, vector<int>(col, -1));
    int index = 0;
    int row_start = 0;
    int row_end = row - 1;
    int col_start = 0;
    int col_end = col - 1;
    int r = row;
    int c = col;
    row = 0;
    col = 0;
    while (row_start <= row_end and col_start <= col_end)
    {
        // when we print 1st row , row_number is same col number varies
        row = row_start;
        for (int i = col_start; i <= col_end; i++)
        {
            mat[row][i] = v[index];
            index++;
        }

        row_start++;
        // printing columns , col number will remain constant row number will change
        col = col_end;
        for (int i = row_start; i <= row_end; i++)
        {
            mat[i][col] = v[index];
            index++;
        }

        col_end--;
        // printing last row
        row = row_end;
        for (int i = col_end; i >= col_start; i--)
        {
            mat[row][i] = v[index];
            index++;
        }

        row_end--;
        // printing first col
        col = col_start;
        for (int i = row_end; i >= row_start; i--)
        {
            mat[i][col] = v[index];
            index++;
        }

        col_start++;
    }
    return mat;
}

int main()
{
    // 2 ip matrixs a 2d and a 1d , fill 2d with contents of 1d in spiral order and return 2d
    // dimensions of 2dmatrix will be given to us and rol*col==num of elements in 1d mat so no doubt of underfitting
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    print1d(v);
    vector<vector<int>> mat = solve(v, 3, 3);
    print2d(mat);
    return 0;
}