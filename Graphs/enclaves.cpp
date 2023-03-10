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


void dfs(vector<vector<int>> &v,int r,int c){
    if(r<0 or c<0 or r>=v.size() or c>=v[0].size()){
        return ;
    }
    if(v[r][c]==0 or v[r][c]==-1){
        return;
    }
    //reached here means its 1
    v[r][c]=-1;
    dfs(v,r-1,c);
    dfs(v,r+1,c);
    dfs(v,r,c-1);
    dfs(v,r,c+1);
}

int main()
{
    vector<vector<int>> v={{0,0,0,1,1,1,0,1,0,0},{1,1,0,0,0,1,0,1,1,1},{0,0,0,1,1,1,0,1,0,0},{0,1,1,0,0,0,1,0,1,0},{0,1,1,1,1,1,0,0,1,0},{0,0,1,0,1,1,1,1,0,1},{0,1,1,0,0,
0,1,1,1,1},{0,0,1,0,0,1,0,1,0,1},{1,0,1,0,1,1,0,0,0,0},{0,0,0,0,1,1,0,0,0,1}};
    print2d(v);
    //mark all 1 that can be accessed from boundary as -1
    int row=v.size()-1;
    int col=v[0].size()-1;
    for(int r=0;r<row;r++){
        dfs(v,r,0);
        dfs(v,r,col);
    }
    for(int c=0;c<col;c++){
        dfs(v,0,c);
        dfs(v,row,c);
    }
    int count=0;
    print2d(v);
    //count the number of 1s
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(v[i][j]==1){
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}