#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<char,int> pp;
    string removeDuplicates(string s, int k) {
        vector<pp> v1;
        //used a vector to mimic a stack
        pp p1;
        p1.first=s[0];
        p1.second=1;
        v1.push_back(p1);
        for(int i=1;i<s.length();i++){
            char c=s[i];
            pp p1=v1.back();
            if(p1.first==c){
                if(p1.second==k-1){
                    v1.pop_back();
                    continue;
                }
                else{
                    p1.second+=1;
                    v1.back()=p1;
                }
            }
            else{
                //doesnt match
                p1.first=c;
                p1.second=1;
                v1.push_back(p1);
            }
        }
        //vector completly formed
        string res="";
        for(auto p2:v1){
            int count=0;
            while(count<p2.second){
                res.push_back(p2.first);
                count++;
            }
        }
        return res;
    }

int main(){
    string s="deeedbbcccbdaakkllssftttfwwwfslk";
int k=3;
string final=removeDuplicates(s,k);
cout<<"Ans is: "<<final<<endl;
    return 0;
}