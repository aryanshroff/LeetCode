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





typedef pair<int, int> pi;

bool check(int i,int j,int r,int c,vector<vector<int>> &ipm){
    if(i<0 or i>=r or j<0 or j>=c){
        return false;
    }
    else if(ipm[i][j]>=0){
        return false;
    }
    return true;
}

void lrud(int i,int j,vector<vector<int>> &ipm,int r,int c,queue<pi> &q){
    int cell=ipm[i][j]+1;
    //left
    if(check(i-1,j,r,c,ipm)==true){
        q.push({i-1,j});
        ipm[i-1][j]=cell;
    }
    //right
    if(check(i+1,j,r,c,ipm)==true){
        q.push({i+1,j});
        ipm[i+1][j]=cell;
    }
    //up
    if(check(i,j-1,r,c,ipm)==true){
        q.push({i,j-1});
        ipm[i][j-1]=cell;
    }
    //down
    if(check(i,j+1,r,c,ipm)==true){
        q.push({i,j+1});
        ipm[i][j+1]=cell;
    }
}

void solve(vector<vector<int>> &ipm){
    queue<pi> q;
    int row=ipm.size();
    int col=ipm[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(ipm[i][j]==0){
                q.push({i,j});
            }
            else{
                ipm[i][j]=-1;
            }
        }
    }
    //print2d(ipm);
    //initialisation done
    while(q.empty()==false){
        pi x=q.front();
        //cout<<"{"<<x.first<<","<<x.second<<"}"<<endl;
        lrud(x.first,x.second,ipm,row,col,q);
        //print2d(ipm);
        q.pop();
    }
}

int main()
{
    vector<vector<int>> ipm2={{1,1,1},{1,1,0},{1,1,1}};
    vector<vector<int>> ipm= {{1, 0, 1, 1, 0, 0, 1, 0, 0, 1}, {0, 1, 1, 0, 1, 0, 1, 0, 1, 1}, {0, 0, 1, 0, 1, 0, 0, 1, 0, 0}, {1, 0, 1, 0, 1, 1, 1, 1, 1, 1}, {0, 1, 0, 1, 1, 0, 0, 0, 0, 1}, {0, 0, 1, 0, 1, 1, 1, 0, 1, 0}, {0, 1, 0, 1, 0, 1, 0, 0, 1, 1}, {1, 0, 0, 0, 1, 1, 1, 1, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 0, 1, 0}, {1, 1, 1, 1, 0, 1, 0, 0, 1, 1}};
    print2d(ipm);
    solve(ipm);
    print2d(ipm);
    return 0;
}