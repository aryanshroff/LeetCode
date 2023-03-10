//generate all subarrays
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


void generate(vector<vector<char>> &res,vector<char> &v){
    int n=v.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            vector<char> temp;
            for(int k=i;k<=j;k++){
                temp.push_back(v[k]);
            }
            res.push_back(temp);
        }
    }
print2d(res);
}

void check(vector<vector<char>> &res,vector<vector<char>> &palins){
    
}

int main()
{
    vector<char> v={'a','b','c','d','e','f'};
    vector<vector<char>> res;
    generate(res,v);
    vector<vector<char>> palins;

    return 0;
}