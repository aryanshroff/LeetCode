#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print1d(vector<T> v){
    cout<<" 1D VECTOR "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
}

template <typename T> 
void print2d(vector<vector<T>> v){
    cout<<" 2D VECTOR "<<endl;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}

template <typename T>
void printstack(stack<T> s ){
    cout<<" STACK "<<endl;
    while(s.empty()==false){
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl;
    cout<<endl;
}

template <typename T>
void printq(queue<T> q){
    cout<<" QUEUE "<<endl;
    while(q.empty()==false){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    cout<<endl;
}

template <class K ,class V>
void printhash(unordered_map<K,V> h){
    cout<<" HASHMAP "<<endl;
    for(auto it=h.begin();it!=h.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<endl;
    cout<<endl;
}


class Edge
{
public:
    int parent_index;
    int child_index;
    int wt;
    Edge(int parent_index = 0, int child_index = 0, int wt = 0)
    {
        this->child_index = child_index;
        this->wt = wt;
        this->parent_index = parent_index;
    }
    void myself()
    {
        cout << "p: " << parent_index << " c: " << child_index << " wt: " << wt << endl;
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

    
void push_Edges(priority_queue<Edge,vector<Edge>,Cmp> pq, int &parent_index, vector<vector<Edge>> &edge_vector)
{
    int n = edge_vector[parent_index].size();
    for (int i = 0; i < n; i++)
    {
        pq.push(edge_vector[parent_index][i]);
    }
}

void dij(vector<int> &nodes, vector<vector<int>> &v, vector<vector<int>> &g,vector<int> &distance, int &n, int &source)
{
    // step1 creating edge vector => adjecentcy vector of edges from given matrix
    vector<vector<Edge>> edge_vector;
    for (int i = 0; i < n; i++)
    {
        vector<Edge> temp;
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] != 0)
            {
                Edge obj1(i, j, v[i][j]);
                temp.push_back(obj1);
                obj1.myself();
            }
        }
        edge_vector.push_back(temp);
    }
    // tyhe edge vector is created
    // we push the source ke saare saare edges into a pq
    priority_queue<Edge,vector<Edge>,Cmp> pq;
    push_Edges(pq, source, edge_vector);
    
    
    
    distance[source]=0;
    while (pq.empty() != false)
    {
        Edge top = pq.top();
        pq.pop();
        top.myself();
        int child_index=top.child_index;
        int parent_index=top.parent_index;
        int wt=top.wt;
        //performing relaxation
        if(distance[child_index]>distance[parent_index]+wt){
            distance[child_index]=distance[parent_index]+wt;
            g[parent_index][child_index]=wt;
            push_Edges(pq,child_index,edge_vector);
        }
        //time to add all nodes of child to the pq
        
    }
}

int main()
{
    vector<int> nodes = {10, 20, 30, 40, 50};
    vector<vector<int>> v = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};
    int n = nodes.size();
    int single_Source_vertex = 0;
    vector<vector<int>> Graph(n, vector<int>(n, 0));
    vector<int> distance(n, INT16_MAX);
    dij(nodes,v,Graph,distance,n,single_Source_vertex);
    print2d(v);
    print2d(Graph);
    print1d(distance);
    return 0;
}