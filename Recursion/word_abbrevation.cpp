#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print1d(vector<T> v){
    cout<<" 1D VECTOR "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
}



string push_count(string ans,int count){
    while(count!=0){
        int digit=count%10+48;
        count=count/10;
        char y=(char)digit;
        ans.push_back(y);
    }
    return ans;
}

    void solve(string &word,vector<string> &v,int ipas, string ans,int count){
        if(ipas==0){
            if(count!=0){
                ans=push_count(ans,count);
            }
            reverse(ans.begin(),ans.end());
            v.push_back(ans);
            return;
        }
        string temp=ans;
        char x=word[ipas-1];
        if(count!=0){
            ans=push_count(ans,count);
        }
        ans.push_back(x);
        solve(word,v,ipas-1,ans,0);
        /*Now its time to push 1, rather than pushing 1 we increment count 
        before any charecter push , we push count */
        ans=temp;
        count++;
        solve(word,v,ipas-1,ans,count);
}

void word_abbrevate(string word){
    vector<string> v;
    solve(word,v,word.length(),"",0);
    cout<<word<<endl;
    print1d(v);
    cout<<endl;
    cout<<endl;
}

int main()
{
    word_abbrevate("pep");
    word_abbrevate("Aryan");

    return 0;
}