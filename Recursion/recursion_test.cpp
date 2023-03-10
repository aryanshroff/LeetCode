#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

int t=45;
vector <int> v1(t,-1); //v1 is global array
static vector <int> v4(t,-1); //v4 will be global static array



int fibo(int n){
    if(n==0 or n==1){
        return n;
    }
    else{
        int x=0,y=0;
        if(v1[n-1]!=-1){
            x=v1[n-1];
        }
        else{
            x=fibo(n-1);
            v1[n-1]=x;
        }
        if(v1[n-2]!=-1){
            y=v1[n-2];
        }
        else{
            y=fibo(n-2);

            v1[n-2]=y;
        }
        v1[n]=x+y;
        return x+y;

    }
}

int fibo2(int n){
    if(n==0 or n==1){
        return n;
    }
    else{
        int x=0,y=0;
        if(v4[n-1]!=-1){
            x=v4[n-1];
        }
        else{
            x=fibo2(n-1);
            v4[n-1]=x;
        }
        if(v4[n-2]!=-1){
            y=v4[n-2];
        }
        else{
            y=fibo2(n-2);
            v4[n-2]=y;
        }
        v4[n]=x+y;
        return x+y;

    }
}

int fibo3(int n,vector <int> v2){
    if(n==0 or n==1){
        return n;
    }
    else{
        int x=0,y=0;
        if(v2[n-1]!=-1){
            x=v2[n-1];
        }
        else{
            x=fibo3(n-1,v2);
            v2[n-1]=x;
        }
        if(v2[n-2]!=-1){
            y=v2[n-2];
        }
        else{
            y=fibo3(n-2,v2);
            v2[n-2]=y;
        }
        v2[n]=x+y;
        return x+y;

    }
}

int fibo4(int n,vector <int>& v3){
    if(n==0 or n==1){
        return n;
    }
    else{
        int x=0,y=0;
        if(v3[n-1]!=-1){
            x=v3[n-1];
        }
        else{
            x=fibo4(n-1,v3);
            v3[n-1]=x;
        }
        if(v3[n-2]!=-1){
            y=v3[n-2];
        }
        else{
            y=fibo3(n-2,v3);
            v3[n-2]=y;
        }
        v3[n]=x+y;
        return x+y;

    }
}

void display(vector <int> v){
    cout<<"[ ";
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<" ]"<<endl;
}

int main(){
    int n;
    
    n=42
    ;
    vector <int> v2(t,-1); //v2 will be passed by value
    vector <int> v3(t,-1); //v3 will be passed by reference
    
    int ans=fibo(n);
    cout<<"Global array is: "<<endl;
    display(v1);
    cout<<"Answer for global array v1: "<<ans<<endl;
    cout<<endl;
    cout<<endl;

    ans=fibo2(n);
    cout<<"Global Static array is: "<<endl;
    display(v4);
    cout<<"Answer for global static array v4: "<<ans<<endl;
    cout<<endl;
    cout<<endl;

    ans=fibo4(n,v3);
    cout<<"Vector passed by reference is: "<<endl;
    display(v3);
    cout<<"Answer for Vector passed by reference v3: "<<ans<<endl;
    cout<<endl;
    cout<<endl;

    ans=fibo3(n,v2);
    cout<<"Vector passed by value is: "<<endl;
    display(v2);
    cout<<"Answer for Vector passed by value v2: "<<ans<<endl;
    return 0;
}