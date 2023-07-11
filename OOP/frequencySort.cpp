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
class Data
{
public:
    int value;
    int freq;
    int index;
    Data(int v, int f, int i){
        value=v;
        freq=f;
        index=i;

    }
};

bool cmp(Data a,Data b){
    if(a.freq>b.freq){
        return true;
    }
    if(a.freq==b.freq){
        if(a.index<b.index){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

void mymain()
{
    vector<int> v={6,6,6,6,3,3,3,3,2,2,11,11,55,44,6,7,888,76};
    unordered_map<int, int> h;
    unordered_map<int,int> occ;
    int n=v.size();
    for(int i=0; i<n; i++){
        h[v[i]]++;
        auto it=occ.find(v[i]);
        if(it==occ.end()){
            occ[v[i]]=i;
        }
    }
    vector<Data> v2;
    for(auto it=h.begin();it!=h.end();it++){
        int first=it->first;
        int second=it->second;
        auto it2=occ.find(first);
        int index=it2->second;
        Data temp(first,second,index);
        v2.push_back(temp);
    }
    sort(v2.begin(),v2.end(),cmp);
    vector<int> res;
    for(int i=0;i<v2.size();i++){
        int value=v2[i].value;
        int f=v2[i].freq;
        while(f>0){
            res.push_back(value);
            f--;
        }
    }
    print1d(res);
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