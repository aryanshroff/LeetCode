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
int subsetSum(int x, int y, int n, vector<int> &left, vector<int> &v)
{
    // both limits are inclusive in nature
    if (x > y)
    {
        return 0;
    }
    else if (x == y)
    {
        return v[x];
    }
    else if (x == 0)
    {
        return left[y];
    }
    else
    {
        return left[y] - left[x - 1];
    }
}

void printState(bool alice, int c1, int v1, int c2, int v2, int start, int end, int depth)
{
    static int count=0;
    string s = "turn: ";
    if (alice)
    {
        s += "Alice ";
    }
    else
    {
        s += "Bob ";
    }
    cout << endl;
    cout << s << " choice1: " << c1 << " val1: " << v1 << " choice2: " << c2 << " val2: " << v2 << " start: " << start << " end: " << end << " depth: " << depth <<" Count: "<<count<< endl;
    count++;
}

int dfs(vector<int> &v, vector<int> left, int start, int end, bool alice, int n, int as, int bs, int depth, unordered_map<string, int> &h)
{
    if (start == end)
    {
        // cout<<"depth: "<<depth<<endl;
        int ans = as - bs;
        cout << "ans: " << ans << endl;
        return ans;
    }
    if (alice == true)
    {
        /*
        string s = "alice_" + to_string(start) + "_" + to_string(end);
        auto it = h.find(s);
        if (it != h.end())
        {
            return it->second;
        }
        */
        // its alices turn
        // as is alice score
        // lets say she picks start limits for next round are start+1,end

        // we are returning alice-bob at all cases hence we always add choice to val
        int choice1 = subsetSum(start + 1, end, n, left, v);
        int val1 = dfs(v, left, start + 1, end, false, n, as + choice1, bs, depth + 1, h);
        int choice2 = subsetSum(start, end - 1, n, left, v);
        int val2 = dfs(v, left, start, end - 1, false, n, as + choice2, bs, depth + 1, h);
        // alice will try to maximise her score
        printState(alice, choice1, val1, choice2, val2, start, end, depth);
        int ans = max(val2, val1);
        cout << "at depth " << depth << " alice returns: " << ans << endl;
        //h[s] = ans;
        return ans;
    }
    else
    {
        // its bobs turn
        // we will return min out of val1 and val2
        /*
        string s = "bob_" + to_string(start) + "_" + to_string(end);
        auto it = h.find(s);
        if (it != h.end())
        {
            return it->second;
        }
        */
        // bobs picks first element
        int choice1 = subsetSum(start + 1, end, n, left, v);
        int val1 = dfs(v, left, start + 1, end, true, n, as, bs + choice1, depth + 1, h);

        // bob picks last element
        int choice2 = subsetSum(start, end - 1, n, left, v);
        int val2 = dfs(v, left, start, end - 1, true, n, as, bs + choice2, depth + 1, h);
        printState(alice, choice1, val1, choice2, val2, start, end, depth);

        int ans = min(val1, val2);
        cout << "at depth " << depth << " bob returns: " << ans << endl;
        //h[s]=ans;
        return ans;
    }
}

int stoneGameVII(vector<int> &v)
{
    // return alice-bob at all times
    // generate sum of subarrays of all lengths from i=0 to i=n
    int n = v.size();
    vector<int> left;
    unordered_map<string, int> h;
    int total = 0, curr_left = 0;
    for (int i = 0; i < n; i++)
    {

        curr_left += v[i];

        left.push_back(curr_left);
    }
    total = curr_left;
    // prefix array is ready
    return dfs(v, left, 0, n - 1, true, n, 0, 0, 1, h);
}

void mymain()
{
    string s = "";
    vector<int> v = {7, 90, 5, 1, 100, 10, 10, 2};

    int result = stoneGameVII(v);
    cout << endl
         << endl;
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