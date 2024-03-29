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
int getState(int a, int b)
{
    return a * 1000 + b;
}

// fill a to brim
// fill b to brim
// empty a
// empty b
// transfer a to b
// transfer b to a

bool canMeasureWater(int x, int y, int t)
{
    if(t>x+y){
        return false;
    }
    queue<pair<int, int>> q;
    int a = 0,tempx=0;
    int b = 0,tempy=0;
    q.push({a, b});
    q.push({-1,-1});
    int sum = 0,state=0;
    unordered_set<int> h;
    h.insert(getState(a, b));
    
    bool res = false;
    while (q.size() >1)
    {
        a = q.front().first;
        b = q.front().second;
        q.pop();
        cout<<a<<" "<<b<<endl;
        if(a==-1  and b==-1){
            q.push({-1,-1});
            continue;
        }

        // fill a to brim
        if(x+b==t){
            res=true;
            break;
        }
        state = getState(x, b);
        if (h.find(state) == h.end())
        {
            h.insert(state);
            q.push({x, b});
        }

        // fill b to brim
        if(a+y==t){
            res=true;
            break;
        }
        state = getState(a, y);
        if (h.find(state) == h.end())
        {
            h.insert(state);
            q.push({a, y});
        }

        // empty a
        if(0+b==t){
            res=true;
            break;
        }
        state = getState(0, b);
        if (h.find(state) == h.end())
        {
            h.insert(state);
            q.push({0, b});
        }

        // empty b
        if(a+0==t){
            res=true;
            break;
        }
        state = getState(a, 0);
        if (h.find(state) == h.end())
        {
            h.insert(state);
            q.push({a, 0});
        }

        // transfer a
        if(a+b>y){
            tempx=a+b-y;
            tempy=y;
        }
        else{
            tempy=a+b;
            tempx=0;
        }
        state = getState(tempx,tempy);
        if(tempx+tempy==t){
            res=true;
            break;
        }
        if (h.find(state) == h.end())
        {
            h.insert(state);
            q.push({tempx, tempy});
        }

        // transfer b
        if(a+b>x){
            tempy=a+b-x;
            tempx=x;
        }
        else{
            tempx=a+b;
            tempy=0;
        }
        state = getState(tempx,tempy);
        if(tempx+tempy==t){
            res=true;
            break;
        }
        if (h.find(state) == h.end())
        {
            h.insert(state);
            q.push({tempx, tempy});
        }
        
    }
    return res;
}

void mymain()
{
    
    int result = canMeasureWater(32,43,7);
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