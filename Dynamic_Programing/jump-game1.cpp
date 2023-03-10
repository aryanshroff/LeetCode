#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &v){
    int n=v.size();
    vector<int> mem(n,0);
    mem[n-1]=1;
    for(int i=n-2;i>=0;i--){
        int cell=v[i];
        while(cell>0){
            if(i+cell<=n-1 and mem[i+cell]==1){
                mem[i]=1;
                break;
            }
            cell--;
        }
        //otherwise its 0 as initialised
    }
    if(mem[0]==1){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    vector<int> v={3,2,1,0,4};
    cout<<solve(v);
    return 0;
}