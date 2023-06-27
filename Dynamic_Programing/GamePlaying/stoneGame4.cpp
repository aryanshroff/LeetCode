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
// we always play from alices perspective we return true for alice wins and flase for alice loss
bool dfs(int n, vector<int> &v, unordered_map<string, bool> &h, int len, bool Alice)
{
    // do not make calls on negative n
    if (Alice == true)
    {
        string s ="alice_"+to_string(n);
        auto it=h.find(s);
        if(it !=h.end()){
            return it->second;
        }
        bool res=false;
        for (int i = 0; i < len; i++)
        {
            int temp = n - v[i];
            if(temp==0){
                //alice ke time pe 0 hua hai means alice wins
                res=true;
                break;
            }
            if(temp<0){
                continue;
            }
            bool branch_value=dfs(temp,v,h,len,false);
            if(branch_value==true){
                res=true;
                break;
            }
        }
        h[s]=res;
        return res;
    }
    else{
        //its bobs turn
        string s="bob_"+to_string(n);
        auto it=h.find(s);
        if(it !=h.end()){
            return it->second;
        }
        bool res=true;
        for (int i = 0; i < len; i++)
        {
            int temp = n - v[i];
            if(temp==0){
                //bob ke time pe 0 hua hai means alice looses
                res=false;
                break;
            }
            if(temp<0){
                continue;
            }
            bool branch_value=dfs(temp,v,h,len,true);
            if(branch_value==false){
                res=false;
                break;
            }
        }
        h[s]=res;
        return res;
        

    }
}

bool winnerSquareGame(int n)
{
    // return true for alice win and false for bob
    // when its alices turn if any of the branch returns true then we return true
    // when its bobs turn  if any branch returns false then we return false
    unordered_map<string, bool> h;
    //inevery recursive call only 2 things change : value of n and whose turn it is
    vector<int> v;
    int limit = pow(n, 0.5);
    for (int i = 1; i <= limit; i++)
    {
        v.push_back(i * i);
    }
    int len = v.size();
    reverse(v.begin(), v.end());
    bool res= dfs(n, v, h, len, true);
    printhash(h);
    return res;
}

void mymain()
{
    string s = "";
    vector<int> test_cases={17};

    for(int i=0; i<test_cases.size();i++){
        int result = winnerSquareGame(test_cases[i]);
        if(result==0){
            s="Bob wins";
        }
        else{
            s="Alice wins";
        }
        cout<<test_cases[i]<<" -> "<<s<<endl;
    }
    
    
    
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