#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

void teb(stack <int> &s,int x){
    //teb-> top element to bottom
    if(s.size()==0){
        s.push(x);
        return ;
    }
    int y=s.top();
    s.pop();
    teb(s,x);
    s.push(y);

}

void sr(stack <int> &s){
    //sr->reverse stack
    if(s.size()==1){
        return ;
    }
    int x=s.top();
    s.pop();
    sr(s);
    teb(s,x);
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
cout<<"before reversal"<<endl;
display(s);
cout<<endl;

cout<<"after reversal"<<endl;
sr(s);
display(s);


return 0;
}