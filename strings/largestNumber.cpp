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
bool cmp(int a,int b){  //return true for a is greater than b
    
    string a1=to_string(a);
    string b1=to_string(b);
    string afirst=a1+b1;
    string bfirst=b1+a1;
    if(afirst>=bfirst){
        return false;
    }
    else{
        return true;
    }
    
}

vector <int> quicksort(vector<int> &nums){
    if(nums.size()<=1){
        cout<<"base case"<<endl;
        return nums;
    }
    else{
        vector <int> LeftARR;
        vector <int> RightARR;
        int pivot=nums[0];
        for(int i=1; i<nums.size();i++){
            int a=nums[i];
            bool val=cmp(a,pivot);
            //true returned means a is greater than pivot
            if(val==true){
                RightARR.push_back(a);
            }
            else{
                LeftARR.push_back(a);
            }
        }
        //entire array is traversed
        vector<int> v1=quicksort(LeftARR);
        vector<int> v2=quicksort(RightARR);
        v1.push_back(pivot);
        for(int i=0; i<v2.size(); i++){
            v1.push_back(v2[i]);
        }
        return v1;
    }
}

vector<int> stlsort(vector<int> &nums){
    sort(nums.begin(), nums.end(),cmp);
    return nums;
}


string largestNumber(vector<int> &nums)
{
    string text="";
    //print1d(nums);
    bool nonZero=false;
    vector<int> res=stlsort(nums);
    int n=res.size();
    for(int i=n-1; i>=0; i--){
        if(nonZero==false and res[i]>0){
            nonZero=true;
        }
        string x=to_string(res[i]);
        text+=x;
    }
    if(nonZero==false){
        return "0";
    }
    return text;
}

void mymain()
{
    string s = "";
    generate(s);
    vector<int> nums={3,30,34,5,9};
    s=largestNumber(nums);
    int result = 0; // call ur function here
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