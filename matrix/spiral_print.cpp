#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void spiral(vector<vector<int>> v){
    int r=v.size();
    int c=v[0].size();
    cout<<"r:"<<r<<" c: "<<c<<endl;
    int row_start=0;
    int row_end=r-1;
    int col_start=0;
    int col_end=c-1;
    int row=0,col=0;
    while(row_start<=row_end and col_start<=col_end){
        //when we print 1st row , row_number is same col number varies
        row=row_start;
        for(int i=col_start;i<=col_end;i++){
            cout<<v[row][i]<<" ";
        }
        cout<<endl;
        row_start++;
        //printing columns , col number will remain constant row number will change
        col=col_end;
        for(int i=row_start;i<=row_end;i++){
            cout<<v[i][col]<<" ";
        }
        cout<<endl;
        col_end--;
        //printing last row
        row=row_end;
        for(int i=col_end;i>=col_start;i--){
            cout<<v[row][i]<<" ";
        }
        cout<<endl;
        row_end--;
        //printing first col
        col=col_start;
        for(int i=row_end;i>=row_start;i--){
            cout<<v[i][col]<<" ";
        }
        cout<<endl;
        col_start++;
        
    }
}

void normal(vector<vector<int>> v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

void Trans(vector<vector<int>> v){
    int r=v.size();
    int c=v[0].size();
    int prin=0;
    for(int i=0;i<r;i++){
        for(int j=i+1;j<c;j++){
            
            
                int temp=v[i][j];
                v[i][j]=v[j][i];
                v[j][i]=temp;
            
        }
        
    }
    normal(v);
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
    spiral(v1);
    cout<<endl;
    cout<<"Transpose :"<<endl;
    Trans(v1);
    return 0;
}