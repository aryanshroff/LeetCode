#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &v,int &start,int &end){
    queue<int> q;
    int n=v.size();
    q.push(start);
    vector<bool> v2(false,n);
    bool ans=false;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        //to check if i==v[i]
        for(int i=0;i<n;i++){
            if(curr+i<n and i==v[curr+i]){
                if(curr+i==end){
                    ans=true;
                    break;
                }
                q.push(i);
                v2[curr+i]=true;
            }
            if(curr-i>0 and i==v[curr-i]){
                if(curr-i==end){
                    ans=true;
                    break ;
                }
                q.push(i);
                v2[curr-i]=true;
                
            }
        }
        if(ans==true){
            break;
        }
    }
    return ans;
}

int main()
{
    vector<int> v={4,2,3,0,3,1,2};
    int end=5;
    int start=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==0){
            start =i;
            break;
        }
    }
    cout<<solve(v,start,end);
    

    return 0;
}