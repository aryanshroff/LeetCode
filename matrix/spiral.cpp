#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> spiral(vector<vector<int>>& v){
    int r=v.size();
    int c=v[0].size();
    int row_start=0;
    int row_end=r-1;
    int col_start=0;
    int col_end=c-1;
    int row=0,col=0;
    vector <int> res;
    while(row_start<=row_end and col_start<=col_end){
        //when we print 1st row , row_number is same col number varies
        
        
        row=row_start;
        cout<<"\nFrom row start"<<endl;
        for(int i=col_start;i<=col_end;i++){
            res.push_back(v[row][i]);
            cout<<v[row][i]<<" ";
        }
        row_start++;

        //printing columns , col number will remain constant row number will change
        cout<<"\nFrom col end"<<endl;
        
        col=col_end;
        for(int i=row_start;i<=row_end;i++){
            res.push_back(v[i][col]);
            cout<<v[i][col]<<" ";
        }
        col_end--;

        //printing last row
        cout<<"\nFrom row end"<<endl;
        if(row_start<=row_end){
            row=row_end;
            //cout<<"row2_end: "<<row<<endl;
            for(int i=col_end;i>=col_start;i--){
                res.push_back(v[row][i]);
                cout<<v[row][i]<<" ";
            }
            row_end--;
        }
        
        //printing first col
        cout<<"\nFrom col start"<<endl;
        if(col_start<=col_end){
            col=col_start;
            for(int i=row_end;i>=row_start;i--){
                res.push_back(v[i][col]);
                cout<<v[i][col]<<" ";
            }
            col_start++;
        }
        
    }
    return res;
}

void normal(vector<vector<int>> v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

int main(){
    vector <vector<int>> v1;
    
    for(int i=0;i<5;i++){
        vector<int> v2;
        for(int j=1+(i*5);j<=5+(i*5);j++){
            
            v2.push_back(j+10);
        }
        v1.push_back(v2);
    }
    normal(v1);
    cout<<endl;
    cout<<endl;

    vector <int> ans=spiral(v1);
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;

    cout<<"Vector 2 "<<endl;
    vector <vector<int>> v2={{1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18}};
    normal(v2);
    cout<<endl;
    cout<<endl;

    ans=spiral(v2);
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<endl;
    cout<<"Vector 3"<<endl;
    vector<vector<int>> v3={{1},{2},{3},{4},{5}};
    normal(v3);
    cout<<endl;
    cout<<endl;

    ans=spiral(v3);
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"Vector 4"<<endl;
    vector<vector<int>> v4={{1,2,3,4,5}};
    normal(v4);
    cout<<endl;
    cout<<endl;

    ans=spiral(v4);
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<endl;
    cout<<"Vector 5"<<endl;
    vector<vector<int>> v5={{1,2,3},{4,5,6}};
    normal(v5);
    cout<<endl;
    cout<<endl;

    ans=spiral(v5);
    for(auto x:ans){
        cout<<x<<" ";
    }

    return 0;
}