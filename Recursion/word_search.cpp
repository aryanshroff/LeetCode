#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;


bool bfs(vector<vector<char>> &v,string &word,int index,int &r,int &c,int i,int j){
    if(index==word.length()){
        return true;
    }
    if(i<0 or i==r or j<0 or j==c){
        return false;
    }
    if(v[i][j]!=word[index]){
        return false;
    }
    //if we reach here means current charecter is matched
    //to prevent reuse we spoil it
    char temp=v[i][j];
    v[i][j]='1';
    index+=1;
    bool left= bfs(v,word,index,r,c,i,j-1);
    bool right=bfs(v,word,index,r,c,i,j+1);
    bool up=bfs(v,word,index,r,c,i-1,j);
    bool down=bfs(v,word,index,r,c,i+1,j);
    v[i][j]=temp;
    return left or right or up or down;
    

}

bool inter(vector<vector<char>> v,string &word,int index,int &r,int &c,int i,int j){
    return bfs(v,word,0,r,c,i,j);
}

bool generate(vector<vector<char>> &v,string &word){
    int r=v.size();
    int c=v[0].size();
    bool ans=false;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            ans=inter(v,word,0,r,c,i,j);
            cout<<"for i: "<<i<<" j: "<<j<<" ans: "<<ans<<endl;
            if(ans==true){
                break;
            }
        }
        if(ans==true){
            break;
        }
    }
    return ans;
}

int main()
{
    vector<vector<char>> v={{'a','b','c','e'},{'s','f','e','s'},{'a','d','e','e'}};
    string word="abceseeefs";
    cout<<generate(v,word);
    return 0;
}