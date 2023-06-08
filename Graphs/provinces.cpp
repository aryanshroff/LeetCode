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

// number of islands
void bfs(vector<vector<int>> &isConnected, vector<int> &visited,int source,int n)
{
    //mark the source as visited
    visited[source] = 1;
    queue<int> q;
    q.push(source);
    while(q.empty()==false){
        int parent = q.front();
        //cout<<"parent: "<<parent<<endl;
        q.pop();
        for(int i=0;i<n;i++){
            if(isConnected[parent][i]==1){
                //make sure the child is unvisited
                if(visited[i]==1){
                    continue;
                }
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int count = 0;
    int n = isConnected.size();
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++)
    {
        //calling bfs of every node
        if(visited[i] ==0){
            count++;
            bfs(isConnected, visited,i,n);
        }
    }
    return count;
}

void mymain()
{
    //cout<<"hello: "<<endl;
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    int res = findCircleNum(isConnected);
    cout << "res: " << res << endl;
}

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