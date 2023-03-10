#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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

class Edge
{
public:
    int wt;
    int parent_index;
    int child_index; // parent and child are basically indices of parent and child
    int parent_val;
    int child_val;
    Edge(int wt = -1, int parent_index = -1, int child_index = -1, int parent_val = -1, int child_val = -1)
    {
        this->wt = wt;
        this->parent_index = parent_index;
        this->child_index = child_index;
        this->child_val = child_val;
        this->parent_val = parent_val;
    }
    void myself()
    {
        cout << "wt: " << wt << " parent_index:" << parent_index << " child_index:" << child_index << " parent_val: " << parent_val << " child_val: " << child_val << endl;
    }
};

class Cmp
{
public:
    bool operator()(Edge &a, Edge &b)
    {
        if (a.wt > b.wt)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

void displayEdgeVector(vector<vector<Edge>> &edge_vector)
{
    for (int i = 0; i < edge_vector.size(); i++)
    {
        cout << "index: " << i << endl;
        for (int j = 0; j < edge_vector[i].size(); j++)
        {
            Edge object = edge_vector[i][j];
            object.myself();
        }
        cout << endl;
        cout << endl;
    }
}

void push_nodes(vector<vector<Edge>> &edge_vector, int &index, priority_queue<Edge, vector<Edge>, Cmp> &pq)
{
    //cout << "index passed: " << index << endl;
    for (int i = 0; i < edge_vector[index].size(); i++)
    {
        pq.push(edge_vector[index][i]);
    }
}

int prims(vector<vector<int>> &v, vector<int> &node, vector<vector<int>> &MST, int &n)
{
    int cost = 0;

    vector<vector<Edge>> edge_vector;
    for (int i = 0; i < n; i++)
    {
        vector<Edge> temp;
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] != 0)
            {
                Edge e1(v[i][j], i, j, node[i], node[j]);
                temp.push_back(e1);
            }
        }
        edge_vector.push_back(temp);
    }

    //displayEdgeVector(edge_vector);
    // we have node vector to get node vale from index
    // we are creating a hashmap h to get index from node value

    unordered_map<int, int> h;
    for (int i = 0; i < n; i++)
    {
        h[node[i]] = i;
    }

    priority_queue<Edge, vector<Edge>, Cmp> pq;
    unordered_set<int> visited;
    // pick a node as origin , push all edges of origin to pq
    // let 0th index node be origin thus the vector at index 0 of edge vector stores all the relevant edges
    int index = 0;
    push_nodes(edge_vector, index, pq);
    visited.insert(index);
    vector<Edge> selected_edges;
    while (pq.empty() == false)
    {
        Edge least = pq.top();
        pq.pop();

        // to ensure the child is unvisited
        int node_val = least.child_index;
        if (visited.find(node_val) != visited.end())
        {
            // the node already has been visited
            continue;
        }
        
        
        // we reached here means the node isnt visited
        // add the node to visited list and add all edges surrounding it !
        visited.insert(node_val);
        selected_edges.push_back(least);
        // to obtain index of nodeval

        cost += least.wt;
        push_nodes(edge_vector, node_val, pq);
    }
    // construct a 2d of our selected edges
    for (int i = 0; i < selected_edges.size(); i++)
    {
        Edge obj1 = selected_edges[i];
        
        int y=obj1.child_index;
        int x=obj1.parent_index;
        MST[x][y]=obj1.wt;
        MST[y][x]=obj1.wt;
    }
    return cost;
}

int main()
{
    // instead of storing 1 for edge and 0 for not edge we store edge wt for edge and 0 for non edge
    vector<int> nodes = {10, 20, 30, 40, 50};
    vector<vector<int>> v = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};
    int n = nodes.size();
    vector<vector<int>> MST(n,vector<int>(n,0));
    int ans = prims(v, nodes, MST, n);
    cout << "Cost of MST is: " << ans << endl;
    cout<<"Given graph :"<<endl;
    print2d(v);
    cout<<"Resultant MST is:"<<endl;
    print2d(MST);
    cout << endl;
    return 0;
}