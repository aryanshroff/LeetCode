#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

typedef pair<string,int> pp;
    struct cmp{
        bool operator()(pp p1,pp p2){
             int f1=p1.second;
             int f2=p2.second;
             cout<<" for p1: "<<p1.first<<" for p2: "<<p2.first<<endl;
            if(f1>f2){
                cout<<"f1>f2"<<endl;
                return true;
            }
            else if(f1==f2){
                if(p1.first<p2.first){
                    cout<<"f1==f2 , first<second"<<endl;

                    return true;
                }
                else{
                    cout<<"f1==f2 , first>second"<<endl;

                    return false;
                }
            }
            else{
                cout<<"f1<f2"<<endl;

                return false;
            }
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map <string,int> h;
        for(auto x:words){
            h[x]++;
        }
        //hashmap of string , frequency created
        
        //type of pair => string<frequency,length>
        
        //implemented min heap of datatype pp
        priority_queue <pp,vector<pp>,cmp> minh;
        for(auto x:h){
            pp p1;
            string s=x.first;
            int len=s.length();
            int freq=x.second;
            
            p1.first=s;
            p1.second=freq;
            
            minh.push(p1);
            if(minh.size()>k){
                minh.pop();
            }
        }
        vector <string> ans;
        while(minh.empty()==false){
            pp p1=minh.top();
            ans.push_back(p1.first);
            minh.pop();
        }
        //reverse(ans.begin(),ans.end());
        return ans;
    }

void displayVect1(vector <string> v1){
    cout<<"[";
    for(auto x:v1){
        cout<<x<<", ";
    }
    cout<<"]"<<endl;
    cout<<endl;
}

int main(){
    vector <string> v={"i","love","leetcode","i","love","coding"};
//{"plpaboutit","jnoqzdute","sfvkdqf","mjc","nkpllqzjzp","foqqenbey","ssnanizsav","nkpllqzjzp","sfvkdqf","isnjmy","pnqsz","hhqpvvt","fvvdtpnzx","jkqonvenhx","cyxwlef","hhqpvvt","fvvdtpnzx","plpaboutit","sfvkdqf","mjc","fvvdtpnzx","bwumsj","foqqenbey","isnjmy","nkpllqzjzp","hhqpvvt","foqqenbey","fvvdtpnzx","bwumsj","hhqpvvt","fvvdtpnzx","jkqonvenhx","jnoqzdute","foqqenbey","jnoqzdute","foqqenbey","hhqpvvt","ssnanizsav","mjc","foqqenbey","bwumsj","ssnanizsav","fvvdtpnzx","nkpllqzjzp","jkqonvenhx","hhqpvvt","mjc","isnjmy","bwumsj","pnqsz","hhqpvvt","nkpllqzjzp","jnoqzdute","pnqsz","nkpllqzjzp","jnoqzdute","foqqenbey","nkpllqzjzp","hhqpvvt","fvvdtpnzx","plpaboutit","jnoqzdute","sfvkdqf","fvvdtpnzx","jkqonvenhx","jnoqzdute","nkpllqzjzp","jnoqzdute","fvvdtpnzx","jkqonvenhx","hhqpvvt","isnjmy","jkqonvenhx","ssnanizsav","jnoqzdute","jkqonvenhx","fvvdtpnzx","hhqpvvt","bwumsj","nkpllqzjzp","bwumsj","jkqonvenhx","jnoqzdute","pnqsz","foqqenbey","sfvkdqf","sfvkdqf"};
    
    int k=4;
    cout<<"Given vector: ";
    displayVect1(v);
    vector <string> ans=topKFrequent(v,k);
    cout<<"Final answer is: "<<endl;
    displayVect1(ans);
    return 0;
}


/*
{"plpaboutit","jnoqzdute","sfvkdqf","mjc","nkpllqzjzp","foqqenbey","ssnanizsav","nkpllqzjzp","sfvkdqf","isnjmy","pnqsz","hhqpvvt","fvvdtpnzx","jkqonvenhx","cyxwlef","hhqpvvt","fvvdtpnzx","plpaboutit","sfvkdqf","mjc","fvvdtpnzx","bwumsj","foqqenbey","isnjmy","nkpllqzjzp","hhqpvvt","foqqenbey","fvvdtpnzx","bwumsj","hhqpvvt","fvvdtpnzx","jkqonvenhx","jnoqzdute","foqqenbey","jnoqzdute","foqqenbey","hhqpvvt","ssnanizsav","mjc","foqqenbey","bwumsj","ssnanizsav","fvvdtpnzx","nkpllqzjzp","jkqonvenhx","hhqpvvt","mjc","isnjmy","bwumsj","pnqsz","hhqpvvt","nkpllqzjzp","jnoqzdute","pnqsz","nkpllqzjzp","jnoqzdute","foqqenbey","nkpllqzjzp","hhqpvvt","fvvdtpnzx","plpaboutit","jnoqzdute","sfvkdqf","fvvdtpnzx","jkqonvenhx","jnoqzdute","nkpllqzjzp","jnoqzdute","fvvdtpnzx","jkqonvenhx","hhqpvvt","isnjmy","jkqonvenhx","ssnanizsav","jnoqzdute","jkqonvenhx","fvvdtpnzx","hhqpvvt","bwumsj","nkpllqzjzp","bwumsj","jkqonvenhx","jnoqzdute","pnqsz","foqqenbey","sfvkdqf","sfvkdqf"};
*/