#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator()(int a,int b){
        if(a>b){
            return true;
        }
        else{
            return false;
        }
    }
};

struct cmp2{
    bool operator()(string a,string b){
        if(a>b){
            return true;
        }
        else{
            return false;
        }
    }
};

void prioQ(vector <int> v1,int k){
    priority_queue <int,vector<int>,cmp> pq;
    for(int x:v1){
        pq.push(x);
        if(pq.size()>k){
            pq.pop();
        }
    }
    //entire vector traversed
    vector <int> ans;
    while(pq.empty()==false){
        ans.push_back(pq.top());
        pq.pop();
    }
    //printing the answer vector
    for(int x:ans){
        cout<<x<<" , ";
    }
    cout<<endl;
}

int main(){
    vector<int> v1={1,2,3,4,5,6};
    int k=6;
    prioQ(v1,k);
    return 0;
}