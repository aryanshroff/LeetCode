#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;

bool check(pi p,int r,int c,vector<vector<int>> &ipm){
    int i=p.first;
    int j=p.second;
    if(i<0 or i>=r or j<0 or j>=c){
        return false;
    }
    if(ipm[i][j]==1){
        return true;
    }
    return false;
}

vector<pi> generate_child(pi p){
    vector<pi> v;
    v.push_back({p.first-1,p.second});
    v.push_back({p.first+1,p.second});
    v.push_back({p.first,p.second-1});
    v.push_back({p.first-1,p.second+1});
    return v;
}

int bfs(vector<vector<int>> &v){
    int r=v.size();
    int c=v[0].size();
    queue<pi> q;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(v[i][j]==2){
                q.push({i,j});
            }
        }
    }
    //all the 2s have been uploaded in the queue
    pi null={-1,-1};
    q.push(null);
    int count=1;
    while(q.empty()==false){
        pi p=q.front();
        q.pop();
        if(p==null){
            count++;
            q.push(null);
            continue;
        }
        vector<pi> v2=generate_child(p);
        for(int i=0;i<v2.size();i++){
            if(check(v2[i],r,c,v)==true){
                int a=v2[i].first;
                int b=v2[i].second;
                //rott the orange
                v[a][b]=2;
                //this acts as a seperate rottener
                q.push({a,b});
            }
        }
    }
    //here q is emptied
    bool flag1=false;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(v[i][j]==1){
                flag1=true;
                break;
            }
        }
    }
    if(flag1==true){
        return -1;
    }
    else{
        return count;
    }
}

int main()
{
    vector<vector<int>> v={{2,1,1},{1,1,0},{0,1,1}};
    cout<<bfs(v);
    return 0;
}