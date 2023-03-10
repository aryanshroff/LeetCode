#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double solve(double x,int n){
    if(n==1){
        return x;
    }
    if(n==0){
        return 1;
    }
    double y=solve(x,n/2);

    if(n%2==0){
        return y*y;
    }
    else{
        return y*y*x;
    }
}

int main()
{
    double ans=solve(2.675,10);
    cout<<ans;
    return 0;
}