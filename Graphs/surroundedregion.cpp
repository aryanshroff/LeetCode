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

void printAdjList(vector<pair<int, int>> adj[], int start, int length)
{
    int n = length;
    // start index is if u want to print from 0 to length n for n vertices
    // or from index 1 to length n+1 for n vertices .
    // is nomenclature of vertices in ur graph problem is 0 to n-1 type 0 to n else for 1 to n nomenclature type 1,n+1
    for (int i = start; i < n; i++)
    {
        cout << i << " -> " << endl;
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j].first << " and cost is : " << adj[i][j].second << endl;
        }
        cout << endl;
        cout << endl;
    }
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// call generate function to generate 2d vector from string s

//************************************************************************************************************************************************************************************************
//************************************************************************************************************************************************************************************************
void dfs(vector<vector<char>> &m, int row, int col, int i, int j)
{
    if (i < 0 or i >= row or j < 0 or j >= col)
    {
        return;
    }
    else if (m[i][j] == 'X' or m[i][j] == 'T')
    {
        return;
    }
    else
    {
        // current cell is 0
        m[i][j] = 'T';
        dfs(m, row, col, i - 1, j);
        dfs(m, row, col, i + 1, j);
        dfs(m, row, col, i, j - 1);
        dfs(m, row, col, i, j + 1);
        return;
    }
}

void solve(vector<vector<char>> &board)
{
    int row = board.size();
    int col = board[0].size();
    // identify border cells and run dfs on them
    
    for(int i=0;i<row;i++){
        if(board[i][0]=='O'){
            dfs(board,row,col,i,0);
        }
        if(board[i][col-1]=='O'){
            dfs(board,row,col,i,col-1);
        }
    }

    for(int j=0;j<col;j++){
        if(board[0][j]=='O'){
            dfs(board,row,col,0,j);
        }
        if(board[row-1][j]=='O'){
            dfs(board,row,col,row-1,j);
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
            else if (board[i][j] == 'T')
            {
                board[i][j] = 'O';
            }
        }
    }
}

void mymain()
{
    string s = "";
    generate(s);
    int result = 0; // call ur function here
    cout << "result: " << result << endl;
}

//************************************************************************************************************************************************************************************************
//************************************************************************************************************************************************************************************************

int main()
{
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