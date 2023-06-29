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
typedef pair<double,int> pi; //probablity , node 
double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
{
    //converting the edges to a 2d adjacency matrix
    double res=0;
    vector<vector<double>> graph (n,vector<double>(n,0)); //0 means no edge exists
    for(int i=0;i<edges.size();i++){
        int parent=edges[i][0];
        int child=edges[i][1];
        graph[parent][child]=succProb[i];
        graph[child][parent]=succProb[i];
    }
    //undirected graph is ready
    print2d(graph);
    
    //time to write a diakstra code
    //we want max probablity upwards
    priority_queue<pi> pq;
    //initialising distance as -1
    vector<double> ans(n,-1);
    ans[start]=1;
    pq.push({1,start});
    while(pq.empty()==false){
        double p=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        //obtaining all children of node
        for(int i=0;i<n;i++){
            if(graph[node][i]!=0){
                double prob=graph[node][i];
                double BayesProbability=ans[node]*prob; //this is probablity from source to i
                if(ans[i]<BayesProbability){ //relation performed
                    ans[i]=BayesProbability;
                    pq.push({BayesProbability,i});
                }
            }
        }
    }

    res=ans[end];
    return res;
}

void mymain()
{
    string s = "[[0,1],[1,2],[0,2]]";
    generate(s);
    vector<vector<int>> edges={{0,1},{1,2},{0,2}};
    vector<double> succProb={0.5,0.5,0.2};
    double result = maxProbability(3,edges,succProb,0,2 );
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