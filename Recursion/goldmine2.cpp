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

bool check(int r, int c,int blocked_col,int blocked_row){
    if(r==blocked_row and c==blocked_col){
        return false;
    }
    else{
        return true;
    }
}

int solve(vector<vector<int>> &v,int r,int c,int blocked_col,int blocked_row){
    if(v[r][c]==0){
        return 0;
    }
    int a1=0,a2=0,a3=0,a4=0,a5=0,a6=0;
    int curr=v[r][c];
    //up
    
    if(r-1>=0 and check(r-1,c,blocked_col,blocked_row)==true){
        a1=solve(v,r-1,c,c,r);
    }
    //down
    if(r+1<v.size() and check(r+1,c,blocked_col,blocked_row)==true){
        a2=solve(v,r+1,c,c,r);
    }
    //right
    if(c+1<v[0].size() and check(r,c+1,blocked_col,blocked_row)==true){
        a3=solve(v,r,c+1,c,r);
    }
    //left
    if(c-1>=0 and check(r,c-1,blocked_col,blocked_row)==true){
        a4=solve(v,r,c-1,c,r);
    }
    a5=max(a1,a2);
    a6=max(a3,a4);

    return max(a5,a6)+curr;
}

int main()
{
    vector<vector<int>> v={{1,0,7,0,0,0},{2,0,6,0,1,0},{3,5,6,7,4,2},{4,3,1,0,2,0},{3,0,5,0,20,0}};
    int ans=0;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            ans=max(ans,solve(v,i,j,-1,-1));
        }
    }
    cout<<ans<<endl;
    return 0;
}