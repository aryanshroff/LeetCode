#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int trielen =26;

class Trie{
    public:
    vector<Trie*> children;
    bool isEnd;
    Trie(){
        isEnd=false;
        for(int i=0;i<trielen;i++){
            children.push_back(NULL);
        }
    }
};

void insert(Trie* root,string key){
    Trie* curr=root;
    for(int i=0;i<key.length();i++){
        int index=key[i]-'a';
        if(curr->children[index]==NULL){
            Trie* temp=new Trie();
            curr->children[index]=temp;
        }
        curr=curr->children[index];
    }
    curr->isEnd=true;
}

bool search(Trie* root,string key){
    Trie* curr=root;
    
    for(int i=0;i<key.length();i++){
        int index=key[i]-'a';
        if(curr->children[index]==NULL){
            return false;
        }
        curr=curr->children[index];
    }
    //at the end of this loop curr node will correspond to last charecter of key
    return curr->isEnd;
}

void display(Trie *root){
    //display contents of trie
    
    for(int i=0;i<trielen;i++){
        
    }
}



int main()
{
    Trie *root=new Trie();
    vector<string> dict={"bad","bat","geek","geeks","cat","cut","zoo"};
    for(int i=0;i<dict.size();i++){
        insert(root,dict[i]);
    }
    cout<<search(root,"bad")<<endl;
    
    return 0;
}