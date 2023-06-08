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

// 2d vec of charecter to 2d vec of int
void generate(string s)
{
    string res;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '[')
        {
            res.push_back('{');
        }
        else if (s[i] == ']')
        {
            res.push_back('}');
        }
        else
        {
            res.push_back(s[i]);
        }
    }
    cout << res << endl;
    cout << endl;
}

//************************************************************************************************************************************************************************************************
//************************************************************************************************************************************************************************************************
vector<vector<int>> neighbours(int x, int y, int row, int col)
{
    // returns the co-ordinates of the neighbour cells
    vector<vector<int>> res;
    if (y + 1 < col) //right
    {
        res.push_back({x, y + 1});
    }
    if (x + 1 < row) //bottom
    {
        res.push_back({x + 1, y});
    }
    if (y - 1 >= 0) //left
    {
        res.push_back({x, y - 1});
    }
    if (x - 1 >= 0) //top
    {
        res.push_back({x - 1, y});
    }
    return res;
}

int dfs(vector<vector<int>> &grid, int x, int y, int row, int col)
{
    if (grid[x][y] == 0)
    {
        return 0;
    }
    // reached here means non zero cell
    int curr = grid[x][y];
    grid[x][y] = 0;
    // apply dfs on all its neighbours
    vector<vector<int>> res = neighbours(x, y, row, col);
    print2d(res);
    int tempx, tempy = 0;
    for (int i = 0; i < res.size(); i++)
    {
        tempx = res[i][0];
        tempy = res[i][1];
        curr += dfs(grid, tempx, tempy, row, col);
    }
    return curr;
}

int findMaxFish(vector<vector<int>> &grid)
{
    int res = 0;
    int row = grid.size();
    int col = grid[0].size();
    // apply dfs on every cell in the grid
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int curr = dfs(grid, i, j, row, col);
            res=max(res,curr);
        }
    }
    return res;
}

void mymain()
{
    string s = "[[0,5],[8,4]]";
    generate(s);
    int result = 0;
    vector<vector<int>> input = {{0,5},{8,4}};
    result = findMaxFish(input);
    cout << "result: " << result << endl;
}

//************************************************************************************************************************************************************************************************
//************************************************************************************************************************************************************************************************

int main()
{
    // take all input here

    // input end
    chrono::system_clock::time_point start = high_resolution_clock::now();
    mymain();
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