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

//************************************************************************************************************************************************************************************************
//************************************************************************************************************************************************************************************************
void bfs(vector<vector<int>> &graph, int source, vector<int> &components, vector<int> &visited)
{
    // makred the source as visited
    visited[source] = 1;
    int n = graph.size();
    // generate all the children
    queue<int> q;
    q.push(source);
    components.push_back(source);
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (graph[parent][i] == 1 and visited[i] == 0)
            {
                int child = i;
                visited[child] = 1;
                q.push(child);
                components.push_back(child);
            }
        }
    }
}

bool test(vector<int> &components, vector<vector<int>> &graph)
{   
    bool ans=true;
    int n=components.size();
    //print2d(graph);
    for (int i = 0; i < n; i++)
    {
        int parent=components[i];
        for (int j = 0; j < n; j++)
        {
            int child=components[j];
            if(parent==child) continue;
            if(graph[parent][child]==0){
                //cout<<"false case"<<endl;
                return false;
            }
        }
    }
    return ans;
}

int countCompleteComponents(int n, vector<vector<int>> &edges)
{
    int c = 0;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < edges.size(); i++)
    {
        int parent = edges[i][0];
        int child = edges[i][1];
        graph[parent][child] = 1;
        graph[child][parent] = 1;
    }
    // print2d(graph);
    vector<int> visited(n, 0);
    vector<vector<int>> connections;
    for (int i = 0; i < n; i++)
    {
        vector<int> components;
        int source = i;
        if (visited[source] == 1)
        {
            continue;
        }
        bfs(graph, source, components, visited);
        connections.push_back(components);
    }
    print2d(connections);
    // testing every components in the connections vector
    for (int i = 0; i < connections.size(); i++)
    {
        vector<int> components = connections[i];
        if (components.size() == 1)
        {
            c++;
            continue;
        }
        bool res=test(components,graph);
        if(res==true){
            c++;
        }
    }
    return c;
}

void mymain()
{
    int n = 6;
    vector<vector<int>> edges = {{0,1},{0,2},{1,2},{3,4},{3,5}};
    cout << "hello" << endl;
    int res = countCompleteComponents(n, edges);
    cout << "Result: " << res << endl;
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