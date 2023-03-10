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


void solve(vector<string> &res,string &ip,string op,vector<int> visited,int n){
    if(n==0){
        res.push_back(op);
        return ;
    }
    for(int i=0;i<visited.size();i++){
        if(visited[i]==1){
            continue;
        }
        //reached here means the charecter is unvisited
        op.push_back(ip[i]);
        visited[i]=1;
        solve(res,ip,op,visited,n-1);
        op.pop_back();
        visited[i]=0;
    }
}

int main()
{
    string ip="abc";
    vector<string> res;
    int n=ip.length();
    vector<int> visited(n,0);
    string op="";
    solve(res,ip,op,visited,n);
    //0 for unvisited 1 for visited
    print1d(res);
    return 0;
}