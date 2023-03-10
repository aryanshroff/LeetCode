#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*Given a source node s, find shortest distance to every other node from s in a Directed Acyclic Weighted Graph
Given a distance vector that stores distances , if o distance between 2 nodes a,b is given means there is no path at all*/

vector<vector<int>> al; // adjecency list , i is the parent node j is the node to which a directed path goes , m[i][j] will give weight of path
void convert(vector<vector<int>> m)
{
    for (int i = 0; i < m.size(); i++)
    {
        vector<int> x;

        for (int j = 0; j < m[i].size(); j++)
        {
            if (m[i][j] != -1)
            {
                x.push_back(j);
            }
        }
        al.push_back(x);
    }
}

void display(vector<vector<int>> v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<int> shortest(vector<vector<int>> m,int source)
{
    int f = m.size();
    //-1 i.e no path , natural number i.e weight of existing path
    vector<int> indeg(f, 0);
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[i].size(); j++)
        {
            if (m[i][j] != -1)
            {
                indeg[j]++;
            }
        }
    }
    queue<int> q;
    // upload all nodes with indeg 0 to q
    for (int i = 0; i < indeg.size(); i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo; // to store nodes in sorted order
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        topo.push_back(curr);
        // time to get all sibling of curr and reduce their degree
        vector<int> temp = al[curr];
        for (int i = 0; i < temp.size(); i++)
        {
            m[curr][temp[i]]--;
            if (m[curr][temp[i]] == 0)
            {
                // time to upload siblin to the queue
                q.push(temp[i]);
            }
        }
    }
    // topo is ready
    // time to perform relaxation
    vector<int> dist(f, INT32_MAX);
    dist[source]=0;
    for(int i=0;i<dist.size();i++){
        if(source==i){
            continue;
        }
        if(dist[i]>dist[])
    }
}

int main()
{
    vector<vector<int>> m = {{-1, 2, -1, -1, 1, -1}, {-1, -1, 3, -1, -1, -1}, {-1, -1, -1, 6, -1, -1},
     {-1, -1, -1, -1, -1, -1}, {-1, -1, 2, -1, -1, 4}, {-1, -1, -1, 1, -1, -1}};
     int source=0;
    vector<int> ans= shortest(m,source);
    return 0;
}