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
typedef pair<int, int> pi;
vector<int> shortestReach(int n, vector<vector<int>> edges, int s)
{
    // step1 : convert edges to graph
    int parent, child, wt;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    //print2d(edges);
    // 0 means edge doesnt exist and value means edge weight
    
    //print2d(graph);
    int source = s ;
    vector<int> res(n, INT32_MAX);
    // putting source in pq
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pi x = {0, source};
    res[source] = 0;
    pq.push(x);
    while (pq.size() != 0)
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        //cout << "Node: " << node << " Dist: " << dist << endl;
        // insert all children of node to pq
        for (int i = 0; i < n; i++)
        {
            int val = graph[node][i];
            if (val != 0)
            {
                // i is the child and there exists an edge between node and child with edgewt=val
                // only push the child if the relaxation is performed on child
                int currDist = res[i];
                int wt = val + res[node];
                //cout << "child: " << i << " currDist: " << currDist << " val: " << val << " wt: " << wt << endl;
                if (wt < currDist)
                {
                    // perform relaxation on child i and then add it to pq
                    res[i] = wt; // res of i gives distance from source to i
                    //cout << "relaxation , dist_from-source : " << wt << " child_index : " << i << endl;
                    //cout << endl;
                    pq.push({res[i], i});
                }
            }
        }

        // all children are inserted
    }
    //print1d(res);
    return res;
}

void mymain()
{
    string s = "";
    vector<vector<int>> edges = {{1, 2, 24}, {1, 4, 20}, {3, 1, 3}, {4, 3, 12}};
    vector<int> ans = shortestReach(4, edges, 1);
    print1d(ans);
    int result = 0;
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