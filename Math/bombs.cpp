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
bool circleCheck(int xp, int yp, int rp, int xc, int yc)
{
    long long term1, term2, term3;
    term1 = pow(xp - xc, 2);
    term2 = pow(yp - yc, 2);
    term3 = term2 - pow(rp, 2);
    if (term1 + term3 <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void adjList(vector<vector<int>> &bombs, vector<vector<int>> &List, int n)
{
    for (int i = 0; i < n; i++)
    {
        vector<int> temp; // ith index of temp will store all indices of explodable children in bombs
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            // i is parent and j is child
            //  we have to check if j satisfies the circle equation of i
            bool res = circleCheck(bombs[i][0], bombs[i][1], bombs[i][2], bombs[j][0], bombs[j][1]);
            if (res == true)
            {
                temp.push_back(j);
            }
        }
        List.push_back(temp);
    }
    //print2d(List);
    return;
}

int explosionCount(vector<vector<int>> &List, int parent, vector<vector<int>> &bombs, int n)
{
    int count = 1,child=0;
    queue<int> q; // q will store indices of explodable childrem
    q.push(parent);
    q.push(-1);
    vector<bool> visited(n, false);
    visited[parent] = true; // mark true as soon as u enter in the queue
    while (q.size() > 1)
    {
        parent = q.front();
        q.pop();
        if (parent == -1)
        {
            q.push(parent);
            continue;
        }
        // add all unvisited children of parent to q and then mark them visited
        for (int i = 0; i < List[parent].size(); i++)
        {
            child = List[parent][i];
            if (visited[child] == false)
            {
                q.push(child);
                visited[child] = true;
                count++;
            }
        }
    }

    return count;
}

int maximumDetonation(vector<vector<int>> &bombs)
{
    int n = bombs.size();
    // generate an adjecentcy list of parent and explodable children
    vector<vector<int>> List;
    adjList(bombs, List, n);
    // for each parent in above list treat it as source and count number of explosion
    int maxCount = 0, count = 0;
    int source = 0;
    for (int i = 0; i < n; i++)
    {
        count = explosionCount(List, i, bombs, n);
        if (count > maxCount)
        {
            maxCount = count;
            source = i;
            if(maxCount ==n){
                break;
            }
        }
    }
    // the parent with max explosions is to be returned
    return maxCount;
}

void mymain()
{
    string s = "[[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]";
    generate(s);
    vector<vector<int>> bombs = {{1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}};
    int result = maximumDetonation(bombs);
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