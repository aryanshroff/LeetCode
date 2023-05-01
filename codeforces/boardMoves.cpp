#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

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


void function_t(long n, vector<long> &dp)
{
    long f_value, t_value, m;
    for (int i = 1; i < n; i++)
    {
        m = (2 * i) + 1;
        f_value = 4 * (m - 1) * i;
        t_value = dp.back() + f_value;
        dp.push_back(t_value);
    }
}

int main()
{
    long maxv = 0;
    vector<long> v;
    long t, n;
    cin >> t;
    while (t > 0)
    {
        cin >> n;
        v.push_back(n);
        maxv = max(n, maxv);
        t--;
    }
    long limit = (maxv - 1) / 2;
    vector<long> dp;
    dp.push_back(0);
    function_t(limit+1, dp);
    //print1d(dp);
    for (long i = 0; i < v.size(); i++)
    {
        long x = v[i];
        limit = (x - 1) / 2;
        cout <<x<<":"<< dp[limit] << endl;
    }
    return 0;
}