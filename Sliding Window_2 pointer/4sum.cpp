#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void display(vector <int> v){
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    cout<<"line 6"<<endl;
        sort(nums.begin(),nums.end());
        //display(nums);
        cout<<"-2 -2 -1 +1 +1 +2 +2"<<endl;
        cout<<"+0 +1 +2 +3 +4 +5 +6 +7 +8 +9 +10"<<endl;
        int l=0,r=0,s=0,t=target;
        int n=nums.size();
        vector<vector<int>> res;
        for(int i=0;i<=n-4;i++){
    cout<<"line 20"<<endl;

            if((i-1)>=0 and nums[i]==nums[i-1]){
                cout<<"cont from i: "<<i<<endl;
                 continue;
                 }
            vector <int> v1;
            v1.reserve(4);
            for(int j=i+1;j<=n-3;j++){
    cout<<"line 30"<<endl;

                if((j-1)>i and nums[j]==nums[j-1]){
                    cout<<"Cont from j: "<<j<<endl;
                    continue;
                    }
                
                display(v1);
                l=j+1;
                r=n-1;
                t=target-(nums[i]+nums[j]);
                while(l<r){
                    
                    s=nums[l]+nums[r];
                    cout<<"1st: "<<nums[i]<<" 2nd: "<<nums[j]<<" t: "<<t;
                    cout<<" l: "<<nums[l]<<" r: "<<nums[r]<<" s: "<<s<<endl;
                    
                    if(s==t){
                        v1.push_back(nums[i]);
                        v1.push_back(nums[j]);
                        v1.push_back(nums[l]);
                        v1.push_back(nums[r]);
                        
                        if(res.size()==0 or v1!=res.back()){
                            res.push_back(v1);
                        }
                        display(v1);
                        v1.clear();
                        l++;
                        r--;
                    }
                    else if(s<t){
                        l++;
                    }
                    else{
                        r--;
                    }
                }
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
    vector <int> v1={-2,-1,-1,1,1,2,2};
    int t=0;
    vector <vector<int>> res=fourSum(v1,t);
    cout<<endl;
    cout<<endl;
    cout<<"Final Answer"<<endl;
    normal(res);
    return 0;
}