#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//generate all possible binary sequences such that no 2 1s are together but 2 00s together are allowed
template <typename T>
void print1d(vector<T> v){
    cout<<" 1D VECTOR "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
}



void solve(vector<string> &v,string s,int ipas){
    if(ipas==0){
        v.push_back(s);
        return ;
    }
    s.push_back('0');
    solve(v,s,ipas-1);
    s.pop_back();
    if(s[s.length()-1]!='1'){
        s.push_back('1');
        solve(v,s,ipas-1);
    }
}

void generate(int n){
    vector<string> v;
    string s="";
    solve(v,s,n);
    print1d(v);
}

int main()
{
    generate(7);
    return 0;
}