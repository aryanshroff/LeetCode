#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int main()
{
    vector<int> v{1,2,3,4,5};
    unordered_map<int, vector<int>> h;
    h[3]=v;
    for(auto it=h.begin();it!=h.end();it++){
        cout<<it->first<<endl;
    }
    return 0;
}