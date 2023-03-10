#include <iostream>
#include <bits/stdc++.h>
using namespace std;



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

vector<pair<int,int>> p;


bool solve(int n,int r,int c,vector<bool> colcheck,vector<bool> forward,vector<bool> backward,vector<vector<char>> &v){
    if(r=n){
        print2d(v);
        return true;
    }
    for(int i=0;i<c;i++){
        if(colcheck[i]==false and forward[r+c]==false and backward[r-c+(n-1)]==false){
            v[r][i]=='Q';
            colcheck[i]=true;
            forward[r+c]=true;
            backward[r-c+(n-1)]=true;
            //time to check for next row
            bool ans=solve(n,r+1,c,colcheck,forward,backward,v);
            if(ans==true){
                p.push_back({r,i});
                return true;
            }
            else{
                //we need to nullify changes done from line 29 because backtracking told current configuration cant be answer
                colcheck[i]=false;
                forward[r+c]=false;
                backward[r-c+(n-1)]=false;
                v[r][i]='.';
            }
        }
    }
    return false;
}



void generate(int n){
    //our board is n*n
    int row=0,col=0;
    vector<bool> colcheck(n,false);
    vector<bool> forward(2*n-1,false);
    vector<bool> backward(2*n-1,false);
    vector<vector<char>> v(n,vector<char>(n,'.'));

    bool ans=solve(n,row,col,colcheck,forward,backward,v);
    cout<<ans<<endl;
    for(int i=0;i<p.size();i++){
        cout<<p[i].first<<" "<<p[i].second<<endl;
    }
    
}

int main()
{
    
    generate(4);
    
    return 0;
}