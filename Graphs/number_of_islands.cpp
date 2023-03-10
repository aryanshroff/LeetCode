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


typedef pair<int,int> pi;
bool check(int i,int j,int r,int c,vector<vector<int>> &v){
    if(i<0 or i>=r or j<0 or j>=c){
        return false;
    }
    if(v[i][j]==1){
        return true;
    }
    return false;
}

void bfs(queue<pi> &q,vector<vector<int>> &v,int r,int c){
    while(q.empty()==false){
        pi x=q.front();
        q.pop();
        int i=x.first;
        int j=x.second;
        //cout<<"i: "<<i<<"j: "<<j<<endl;
        //up
        if(check(i-1,j,r,c,v)){
    
            v[i-1][j]=5;
            q.push({i-1,j});
        }
        //down
        if(check(i+1,j,r,c,v)){
            v[i+1][j]=5;
            q.push({i+1,j});
        }
        //left
        if(check(i,j-1,r,c,v)){
            v[i][j-1]=5;
            q.push({i,j-1});
        }
        //right
        if(check(i,j+1,r,c,v)){
            
            v[i][j+1]=5;
            
            q.push({i,j+1});
        }
    }
}

int finder(vector<vector<int>> v){
    int r=v.size();
    int c=v[0].size();
    vector<pi> loc;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(v[i][j]==1){
                loc.push_back({i,j});
            }
        }
    }

    cout<<"printing loc of size: "<<loc.size()<<endl;
    for(int i=0;i<loc.size();i++){
        cout<<"{"<<loc[i].first<<","<<loc[i].second<<"}     ";
    }
    cout<<endl;
    int count=0;
    for(int i=0;i<loc.size();i++){
        int x=loc[i].first;
        int y=loc[i].second;
        if(v[x][y]==1){
            count++;
            queue<pi> q;
            v[x][y]=5;
            q.push({x,y});
            bfs(q,v,r,c);
            print2d(v);
        }
    }
    return count;
}



int main()
{
    vector<vector<int>> v={{1,0,1,1,0,0,1,0,0,1},{0,1,1,0,1,0,1,0,1,1},{0,0,1,0,1,0,0,1,0,0},{1,0,1,0,1,1,1,1,1,1},{0,1,0,1,1,0,0,0,0,1},{0,0,1,0,1,1,1,0,1,0},{0
,1,0,1,0,1,0,0,1,1},{1,0,0,0,1,1,1,1,0,1},{1,1,1,1,1,1,1,0,1,0},{1,1,1,1,0,1,0,0,1,1}};
    print2d(v);
    cout<<finder(v)<<endl;
    return 0;
}