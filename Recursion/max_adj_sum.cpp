#include <bits/stdc++.h> 
using namespace std;



int solve(vector<int>& v,int ipas,int sum){
    if(ipas<=0){
        return sum;
    }
    int a=solve(v,ipas-1,sum);
    int b=solve(v,ipas-2,sum+v[ipas-1]);
    return max(a,b);
    
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        int size;
        cin>>size;
        vector<int> v;
        for(int i=0;i<size;i++){
            int x;
            cin>>x;
            v.push_back(x);
            
        }
        //vector<vector<int>> t(size,vector<int>())
        int res=solve(v,size,0);
        cout<<res<<endl;
        t--;
    }
    return 0;
}