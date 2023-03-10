#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string p, string s) {
        unordered_map <char,string> h;
        string temp="";
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                temp+=s[i];
            }
            else{
                auto it=h.find(p[count]);
                if(it==h.end()){
                    h[p[count]]=temp;
                    count++;
                    temp="";
                }
                else{
                    if(temp!=it->second){
                        return false;
                    }
                    else{
                        count++;
                        temp="";
                    }
                }
            }

        }
        return true;
    }

int main(){
    string p="abba";
    string s1="dog cat cat dog";
    string s2="dog cat cat lion";
    cout<<wordPattern(p,s2)<<endl;
    return 0;
}