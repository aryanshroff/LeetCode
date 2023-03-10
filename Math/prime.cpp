#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void display(vector <int> t){
    for(int x:t){
        cout<<x<<" ";
    }
    cout<<endl;
}
//copy from here
vector<bool> prime(int n){
    vector <bool> v(n+1,true);
    v[0]=false;
    v[1]=false;
    //2<=i<=rootn
    for(int i=2;i*i<=n;i++){
        if(v[i]==true){
            for(int j=i*i;j<=n;j+=i){
                v[j]=false;
            }
        }
        
    }
    return v;
}

int count_prime(int n){
    vector <bool> v=prime(n);
    int count=0;
    for(bool x:v){
        if(x==true){
            count++;
        }
    }
    return count;
}

vector<int> get_prime(int n){
    vector<bool> v=prime(n);
    vector<int> ans;
    for(int i=0;i<v.size();i++){
        if(v[i]==true){
            ans.push_back(i);
        }
    }
    return ans;
}

//copy till here

int main(){
    int n=100; //n tak prime numbers chahiye
    int count=count_prime(n);
    vector<int> prime=get_prime(n);

    cout<<"Number of primes is: "<<count<<endl;
    display(prime);
    return 0;
}