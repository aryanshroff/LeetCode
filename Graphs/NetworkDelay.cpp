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

//************************************************************************************************************************************************************************************************
//************************************************************************************************************************************************************************************************
// template <class V, class W>
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

typedef pair<int, int> pi;
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    int delay = 0;
    // generate a res array storing single source shortest path from k
    // return max value of res array , if max==INT_MAX then return -1

    // times array is u,v,wt format lets convert it to graph in adjcentcy list format
    // we have nodes frpm 1 to n i. index 1 to n total length =n+1;
    vector<pair<int, int>> adj[n + 1]; // this is the adjacency list declaration
    int cnt = 0;                       // index counter for times
    for (auto i : times)
    {
        adj[i[0]].push_back({i[1], i[2]});
        cnt++;
    }
    //printAdjList(adj, 1, n + 1);
    vector<int> dist(n + 1, INT32_MAX);
    dist[k] = 0; // source made 0
    // shortest time on top
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, k}); // distance from source , source index
    while (pq.empty() == false)
    {
        pi top = pq.top();
        pq.pop(); //
        int source_to_parent_distance = top.first;
        int parent = top.second;
        // cout<<"source_to_parent_distance: "<<source_to_parent_distance<<" parent: "<<parent<<endl;
        //  to add all children of parent here
        for (int i = 0; i < adj[parent].size(); i++)
        {
            int child = adj[parent][i].first;
            int parent_to_child_distance = adj[parent][i].second;
            if (dist[child] < parent_to_child_distance)
            {
                continue;
            }
            int new_source_to_child_distance = source_to_parent_distance + parent_to_child_distance;
            int prev_source_to_child_distance = dist[child];
            if (prev_source_to_child_distance > new_source_to_child_distance)
            {
                // perform relaxation
                dist[child] = new_source_to_child_distance;
                // upload the current child in pq
                pq.push({dist[child], child});
            }
        }
    }

    //print1d(dist);
    for (int i = 1; i < dist.size(); i++)
    {
        delay = max(delay, dist[i]);
    }
    if (delay == INT32_MAX)
    {
        return -1;
    }
    else
    {
        return delay;
    }
}

void mymain()
{
    string s = "[[2,1,1],[2,3,1],[3,4,1]]";
    generate(s);
    int result = 0;
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    result = networkDelayTime(times, 4, 2);
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