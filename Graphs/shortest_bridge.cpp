#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print1d(vector<T> v)
{
    cout << " 1D VECTOR " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << endl;
}

template <typename T>
void print2d(vector<vector<T>> v)
{
    cout << " 2D VECTOR " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

template <typename T>
void printstack(stack<T> s)
{
    cout << " STACK " << endl;
    while (s.empty() == false)
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
    cout << endl;
}

template <typename T>
void printq(queue<T> q)
{
    cout << " QUEUE " << endl;
    while (q.empty() == false)
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    cout << endl;
}



template <class K, class V>

void printhash(unordered_map<K, V> h)
{
    cout << " HASHMAP " << endl;
    for (auto it = h.begin(); it != h.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;
    cout << endl;
}

typedef pair<int, int> pi;
void displayq(queue<pi> q){
    while(q.empty()==false){
        pi x=q.front();
        cout<<x.first<<" "<<x.second<<endl;
        q.pop();
    }
}
int check(int i,int j,int r, int c,vector<vector<int>> &v){
    
    int val=0;
    if(i<0 or j<0 or i>=r or j>=c){
        val= 0;
    }
    if(v[i][j]==0){
        val= 1;
    }
    if(v[i][j]==5){
       val= 5;
    }
    else{
        val=0;
    }
    cout<<"Checking for i: "<<i<<" j: "<<j<<" value returned: "<<val<<endl;
    return val;
}


int bfs(vector<vector<int>> &v)
{
    int r = v.size();
    int c = v[0].size();
    queue<pi> q;
    //cout<<"line 76"<<endl;
    for (int i = 0; i < r; i++)
    {
        bool flag1 = false;
        bool flag0= false;
        bool flag2=true;
        for (int j = 0; j < c; j++)
        {
            if (v[i][j] == 1 and flag2==true)
            {
                flag1 = true;
                q.push({i, j});
                //cout<<"flag1: "<<flag1<<endl;
            }
            if (v[i][j] == 0 and flag1 == true)
            {
                //cout<<"flag0 is true at row: "<<i<<" col: "<<j<<endl;
                flag0=true;
                flag2=false;
            }
            if(flag1 == true and flag0==true and v[i][j]==1){
                //cout<<"line 116"<<endl;
                v[i][j]=5;
            }
        }
    }
    q.push({-1,-1}); //null marker
    print2d(v);
    
    int count=0;
    while(q.empty()==false){
        cout<<"At count: "<<count<<endl;
        displayq(q);
        pi x=q.front();
        q.pop();
        int i=x.first;
        int j=x.second;
        if(i==-1 and j==-1){
            count++;
            q.push({-1,-1});
            continue;
        }
        
        //left
        int val=check(i,j-1,r,c,v);
        if(val==1){
            v[i][j-1]=1;
            q.push({i,j-1});
        }
        if(val==5){
            break;
        }
        //right
        val=check(i,j+1,r,c,v);
        if(val==1){
            v[i][j+1]=1;
            q.push({i,j+1});
            cout<<"Line 163"<<endl;
        }
        if(val==5){
            break;
        }
        //up
        val=check(i-1,j,r,c,v);
        if(val==1){
            v[i-1][j]=1;
            q.push({i-1,j});
        }
        if(val==5){
            break;
        }
        //down
        val=check(i+1,j,r,c,v);
        if(val==1){
            v[i+1][j]=1;
            q.push({i+1,j});
        }
        if(val==5){
            break;
        }
        
        
    }
    return count;

}
//reconstruct bridge
vector<vector<int>> reconst(vector<vector<int>> &grid){
vector<vector<int>> v;
for(int i=0;i<grid.size();i++){
    vector<int> temp={1};
    for(int j=0;j<grid[0].size();j++){
        temp.push_back(grid[i][j]);
    }
    temp.push_back(1);
    v.push_back(temp);
}
return v;
}


int main()
{
    vector<vector<int>> v ={{0,1},{1,0}};
    print2d(v);
    v=reconst(v);
    print2d(v);
    // {{1, 1,0, 0, 0, 0, 1}, {1, 0,0, 0, 0, 0, 1}, {1, 1,0, 0, 0, 0, 1}, {0, 1, 1, 0,0, 0, 1}};
    
    int ans=bfs(v);
    cout<<ans<<endl;
    return 0;
}