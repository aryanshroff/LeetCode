#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//2d vec of charecter to 2d vec of int
vector<vector<int>> convert(vector<vector<char>> v){
    vector<vector<int>> ans;
    for(int i=0;i<v.size();i++){
        vector<int> temp;
        for(int j=0;j<v[0].size();j++){
            if(v[i][j]=='1'){
                temp.push_back(1);
            }
            else{
                temp.push_back(0);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    string s = "[[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]";
    //string s="[[2,1,1],[1,1,0],[0,1,1]]";
    //string s="[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]";
    string res;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '[')
        {
            res.push_back('{');
        }
        else if (s[i] == ']')
        {
            res.push_back('}');
        }
        else
        {
            res.push_back(s[i]);
        }
    }
    cout << res;
    return 0;
}