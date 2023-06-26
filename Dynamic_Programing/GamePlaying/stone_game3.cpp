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
int solve(bool Alice, int i, int capacity, vector<int> &v, int n,vector<vector<int>> &dp)
{
    if (i >= n)
    {
        // 1st unpicked index is out of bounds
        return 0;
    }
    int res = 0;
    //dp table 0th row is alice and 1st row is bob
    //dp[0][i] for alice at ith index
    if (Alice == true)
    {
        int memo=dp[0][i];
        if(memo!=0){
            return memo;
        }
        // its alices turn to play
        // we gonna return max of all scores returned by all branches
        // hence set res to int min
        res = INT_MIN;
        // x denotes how many elements picked by alice => [1st] or [1st , 2nd] or [1,2,3]
        // at x==0 pick v[i]
        // at x==1 pick v[i]+v[i+1]
        // at x==2 pick v[i] +v[i+1]+v[i+2]
        // store a prefix array
        int prefix = 0;
        for (int x = 0; x < capacity; x++)
        {
            if (i + x < n)
            {
                prefix += v[i + x];
                // we send i+x+1 to recursive call
                int score = prefix + solve(false, i + x + 1, 3, v, n,dp);
                res = max(res, score);
            }
        }
        dp[0][i]=res;
        return res;
    }
    else
    {
        // we are playing for bob hence from all the alice scores we get from next branch we will return the min score
        int memo=dp[1][i];
        if(memo!=0){
            return memo;
        }
        res = INT_MAX;
        for (int x = 0; x < capacity; x++)
        {
            res = min(res, solve(true, i + x + 1, 3, v, n,dp));
        }
        dp[1][i] = res;
        return res;
    }
}

string stoneGameIII(vector<int> &v)
{

    // 3 variables to keep track of
    //  1. whose turn it is
    //  2. current unpicked index i
    //  3. maximum capacity of pick (which is 3 throughout the problem)
    int n=v.size();
    vector<vector<int>> dp(2,vector<int> (n,0));
    int i = 0, capacity = 3;
    int AliceScore = solve(true, i, capacity, v, v.size(),dp);
    int total = 0;
    for (int i = 0; i < v.size(); i++)
    {
        total += v[i];
    }
    int BobScore = total - AliceScore;
    cout << "Alice Score: " << AliceScore << "  BobScore: " << BobScore << endl;
    if (BobScore == AliceScore)
    {
        return "Tie";
    }
    else if (BobScore > AliceScore)
    {
        return "Bob";
    }
    else
    {
        return "Alice";
    }
}

void mymain()
{
    string s = "";

    vector<int> v = {1, 2, 3, -9};
    s = stoneGameIII(v);
    cout << "result: " << s << endl;
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