#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void print1d(vector<int> v){
    cout<<" 1D VECTOR "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
}
int flip=0;
int solve(int n, int k , vector<int> &v){
    int l=v[n-1];
    if(k==l){
        return 1;
    }
    else if(k==1||k==5||k==6){
        return 0;
    }
    else if(k==2 or k==3 or k==4 or k==7){
        return 1;
    }
    int m=(l-1)/2;
    int d=k-m;
    if(d>0){
        flip++;
        return solve(n-1,d,v);
    }
    else{
        return solve(n-1,k,v);
    }
}

int main()
{
    int n=4;
    int k=11;
    vector<int> v={1};
    
    for(int i=1;i<n;i++){
        int val=2*v[i-1]+1;
        //cout<<val<<endl;
        v.push_back(val);
    }
    
    //vector v holds length of s at each n
    int ans=solve(n,k,v);
    flip=flip%2;
    ans=(ans+flip)%2;
    cout<<"for string s"<<n<<" length: "<<v[n-1]<<" answer is: "<<ans<<endl;
    print1d(v);
    return 0;
}