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
bool check(string x, unordered_set<string> &h)
{
    string pure = "";
    bool occured = false;
    bool plus = false;
    int n = x.length();
    if (x[0] == '+' or n < 4 or x[0] == '@' or x[0] == '.')
    {
        return false;
    }
    string f=".com";
    int counter=0;
    for(int i=n-4;i<n;i++){
        if(x[i]!=f[counter]){
            return false;
        }
        counter++;
    }
    // reached here means local name is non empty
    n=n-4;
    int i = 0;
    while (i < n)
    {
        // local name check
        if (x[i] == '@')
        {
            occured = true;
            i++;
            break;
        }
        if (plus == true)
        {
            i++;
            continue;
        }
        if (x[i] == '.')
        {
            i++;
            continue;
        }
        if (x[i] == '+')
        {
            plus = true;
            i++;
            continue;
        }
        // reached here means we have a lower case
        pure += x[i];
        i++;
    }
    pure += '@';
    while (i < n)
    {
        // domain name check
        if (x[i] == '@')
        {
            return false;
        }
        pure+=x[i];
        i++;
    }
    pure+=".com";
    auto it = h.find(pure);
    if (it == h.end())
    {
        h.insert(pure);
        return true;
    }
    else
    {
        return false;
    }
}

int numUniqueEmails(vector<string> &emails)
{
    int count = 0;
    int n = emails.size();
    vector<string> rejected_mails;
    unordered_set<string> h;
    for (int i = 0; i < n; i++)
    {
        string x = emails[i];
        bool val = check(x, h);
        if (val == true)
        {
            count++;
        }
        else{
            rejected_mails.push_back(x);
        }
    }
    cout<<"rejected_mails: "<<endl;
    print1d(rejected_mails);
    return count;
}

void mymain()
{
    string s = "";
    vector<string> emails = {"a@leetcode.com","a.@leetcode.com","b@leetcode.com","c@leetcode.com"};
    
    int result = numUniqueEmails(emails); // call ur function here
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