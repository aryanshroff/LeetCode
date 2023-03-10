#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> l;

void display(vector<vector<int>> v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}

void mat_to_list(vector<vector<int>> m){
    
    for(int i=0;i<m.size();i++){
        vector<int> temp;
        for(int j=0;j<m[i].size();j++){
            if(m[i][j]==1){
                temp.push_back(j);
            }
        }
        l.push_back(temp);
    }
    display(l);

}
//bfs on an adjacentcy list

void bfs(vector<vector<int>> v,unordered_set<int> &h,int source){
    queue <int> q;
    q.push(source);
    h.insert(source);
    cout<<"BFS: ";
    while(!q.empty()){
        int top=q.front();
        q.pop();
        cout<<top<<" ";
        for(int j=0;j<v[top].size();j++){
            int x=v[top][j];
            if(h.find(x)!=h.end()){
                continue;
            }
            q.push(x);
            h.insert(x);
        }//children explored and parent exploited

    }
    cout<<endl;
}

void bfs_search(vector<vector<int>> v){
    unordered_set<int> h;//to keep a track of visited nodes
    //calling bfs on every node to cover on islands
    for(int i=0;i<v.size();i++){
        if(h.find(i)==h.end()){
            bfs(v,h,i);
        }
    }
    


}



int main(){
    vector<vector<int>> v={{0,1,1,0,0,1,0,0},{1,0,0,1,0,0,0,0},{1,0,0,0,1,0,0,0},{0,1,0,0,0,1,0,0},{0,0,1,0,0,1,0,0},{1,0,0,1,1,0,0,0},{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,1,0}};
    display(v);
    mat_to_list(v);
    bfs_search(l);
    return 0;
}