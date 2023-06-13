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
vector<pair<int, int> > neighbours(int x,int y,int row,int col){
    vector<pair<int, int> > res;
    if(x-2>=0){
        if(y-1>=0){
            res.push_back({x-2,y-1 });
        }
        if(y+1<row){
            res.push_back({x-2,y+1});
        }
    }
    if(x-1>=0){
        if(y+2<row){
            res.push_back({x-1,y+2});
        }
        if(y-2>=0){
            res.push_back({x-1,y-2});
        }
    }
    if(x+1<col){
        if(y+2<row){
            res.push_back({x+1,y+2});
        }
        if(y-2>=0){
            res.push_back({x+1,y-2});
        }
    }
    if(x+2<col){
        if(y-1>=0){
            res.push_back({x+2,y-1 });
        }
        if(y+1<row){
            res.push_back({x+2,y+1});
        }
    }
    return res;
}

bool dfs(vector<vector<int>>& grid,int x,int y,int row,int col,int begin){
    if(begin==(row*col)-1){
        return true;
    }
    vector<pair<int,int>> neigh=neighbours(x,y,row,col);
    bool signal=false;
    int childx=0,childy=0;
    for(int i=0;i<neigh.size();i++){
        childx=neigh[i].first;
        childy=neigh[i].second;
        int next=grid[childx][childy];
        if(next==begin+1){
            signal=true;
            break;
        }
    }
    if(signal==false){
        return false;
    }
    else{
        return dfs(grid,childx,childy,row,col,begin+1);
    }
}

bool checkValidGrid(vector<vector<int>> &grid)
{
    int x=0,y=0;
    int row=grid.size();
    int col=grid[0].size();
    int begin=0;
    return dfs(grid,x,y,row,col,begin);
}

void mymain()
{
    string s = "[[8,3,6],[5,0,1],[2,7,4]]";
    generate(s);
    vector<vector<int>> grid={{8,3,6},{5,0,1},{2,7,4}};
    print2d(grid);
    bool result = checkValidGrid(grid);
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