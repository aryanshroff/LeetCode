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

void list_to_mat(vector<vector<int>> v,int vertex){
    vector<vector<int>> m;
    for(int i=0;i<vertex;i++){
        
    }
}




int main(){
    vector<vector<int>> v={{0,1,1,0,0,1,0,0},{1,0,0,1,0,0,0,0},{1,0,0,0,1,0,0,0},{0,1,0,0,0,1,0,0},{0,0,1,0,0,1,0,0},{1,0,0,1,1,0,0,0},{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,1,0}};
    display(v);
    mat_to_list(v);
    
    return 0;
}