#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

void insert(stack <int> &s,int x){
    if(s.size()==0){
        s.push(x);
        return;
    }
    int y=s.top();
    if(y>=x){
        s.push(x);
        return ;
    }
    s.pop();
    insert(s,x);
    s.push(y);
}

void sort(stack <int> &s){
    if(s.size()==1){
        return;
    }
    int x=s.top();
    s.pop();
    sort(s);
    //push x se sorted strack ke upar 9 aa jayga which makes it unsorted again , insert x karte hai
    insert(s,x);
    return;
}



void display(stack <int> s){
    if(s.empty()){
        return ;
    }
    int y=s.top();
    cout<<" "<<y;
    s.pop();
    display(s);
}



int main(){
stack <int> s;
s.push(7);
s.push(2);
s.push(1);
s.push(9);


return 0;
}