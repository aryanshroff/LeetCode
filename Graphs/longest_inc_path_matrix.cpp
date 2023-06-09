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
    // x and y are co-ordinates of current cell
    vector<vector<int>> res;
    if (y + 1 < col) // right
    {
        res.push_back({x, y + 1});
    }
    if (x + 1 < row) // bottom
    {
        res.push_back({x + 1, y});
    }
    if (y - 1 >= 0) // left
    {
        res.push_back({x, y - 1});
    }
    if (x - 1 >= 0) // top
    {
        res.push_back({x - 1, y});
    }
    return res;
}

int dfs(vector<vector<int>> &matrix, vector<vector<int>> &memo, int row, int col, int x, int y)
{
    if (memo[x][y] != 0)
    {
        return memo[x][y];
    }
    vector<vector<int>> res = neighbours(x, y, row, col);
    int max_depth = 1;
    int val = 0;
    for (int i = 0; i < res.size(); i++)
    {
        int childx = res[i][0];
        int childy = res[i][1];
        //can only traverse if they are smaller than the parent value
        int parent=matrix[x][y];
        int child=matrix[childx][childy];
        if(child>=parent){
            val=0;
        }
        else{
            val = dfs(matrix, memo, row, col, childx, childy);
        }
        
        max_depth = max(val + 1, max_depth);
    }
    // reaching here means curr x and y are solved we save it in our memory
    memo[x][y] = max_depth;
    return memo[x][y];
}

int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> memo(row, vector<int>(col, 0));
    int res=0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            res=max(dfs(matrix,memo,row,col,i,j),res);
        }
    }
    //print2d(matrix);
    //print2d(memo);
    return res;
}

void mymain()
{
    string s = "[[9,9,4],[6,6,8],[2,1,1]]";
    generate(s);
    int result = 0;
    vector<vector<int>> matrix = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    result = longestIncreasingPath(matrix);
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