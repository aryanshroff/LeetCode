#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector <string> h;  //has dialpad key
    vector <string> v; //has answers

    void display(vector <string> v){
        for(auto &x:v){
            cout<<x<<" ";
        }
        cout<<endl;
        cout<<endl;
    }
    void status(string ip,string op,int ipss,int last,string s,string op1){
        cout<<" ip: "<<ip<<" op: "<<op<<" ipss: "<<ipss<<" last: "<<last<<" s: "<<s<<" op1: "<<op1<<endl;
    }

    void solve(string &ip,string &op,int ipss){
        if(ipss==0){
            v.push_back(op);
            return;
        }
        int last=ip[ipss-1]-'0';
        string s=h[last];
        string op1=op;
        status(ip,op,ipss,last,s,op1);
        for(int i=0;i<s.length();i++){
            char y=s[i];
            op1.push_back(y);
            solve(ip,op1,ipss-1);
            op1.pop_back();
        }


        
    }

    vector<string> letterCombinations(string digits) {

            h.resize(10);
            h={"-1","-1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
            display(h);
            reverse(digits.begin(),digits.end());
            string op=""; //empty string is an r value
            solve(digits,op,digits.length());
            return v;

        
    }

    

    int main(){
        string digits="666";
        vector<string> y=letterCombinations(digits);
        display(v);

    }

    /* DOUBTS
    1.Why ipss cant be passed by reference
    2.Why cant we send empty string (as r value) to a recursive function
    */