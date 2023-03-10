#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &v){
    int n=v.size();
    vector<int> mem(n,INT_MAX);
    mem[n-1]=0;
    for(int i=n-2;i>=0;i--){
        int cell=v[i];
        int min_jump=INT_MAX;
        while(cell>0){
            if(i+cell<=n-1){
                int val=mem[i+cell];
                min_jump=min(min_jump,val);
            }
            cell--;
        }
        mem[i]=min_jump+1;
        //otherwise its 0 as initialised
    }
    return mem[0];
}

int main()
{
    vector<int> v={2,3,1,1,4};
    cout<<solve(v);
    return 0;
}