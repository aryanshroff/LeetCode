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


void dfs(vector<vector<int>> &v,int &color,int r,int c,int &cell,int &invert){
    int count=0;
    if(v[r][c]==cell){
        v[r][c]=invert;
    }
    //left
    if(c-1>=0){
        if(v[r][c-1]==invert){
        count++;
       }
       if(v[r][c-1]==cell){
        count++;
        dfs(v,color,r,c-1,cell,invert);
       }
       
    }
    //right
    if(c+1<v[0].size()){
        if(v[r][c+1]==invert){
        count++;
       }
       if(v[r][c+1]==cell){
        count++;
        dfs(v,color,r,c+1,cell,invert);
       }
       
    }
    //up
    if(r-1>=0){
        if(v[r-1][c]==invert){
        count++;
       }
       if(v[r-1][c]==cell){
        count++;
        dfs(v,color,r-1,c,cell,invert);
       }
       
    }
    //down
    if(r+1<v.size()){
        if(v[r+1][c]==invert){
        count++;
       }
       if(v[r+1][c]==cell){
        count++;
        dfs(v,color,r+1,c,cell,invert);
       }
       
    }
    //unpaint
    if(count==4){
        v[r][c]=cell;
    }
    //paint
    
}

int main()
{
    vector<vector<int>> v={{1,1},{1,2}};
    int target_color=5;
    int r=0;
    int c=0;
    int cell=v[r][c];
    int invert=cell*(-1);
    dfs(v,target_color,r,c,cell,invert);
    print2d(v);

    return 0;
}