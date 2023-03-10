#include <iostream>
#include <bits/stdc++.h>
using namespace std;



void display(vector <int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
}

//start copy from here
vector<int> tree;
void build(vector<int> &nums,int start,int end,int tn){
    //tn=>tree node i.e index at which filling will be done for this recursive call
    if(start==end){
        tree[tn]=nums[start];
        return;
    }
    int mid=(start/2)+(end/2);
    int left=tn*2;
    int right=left+1;
    build(nums,start,mid,left);
    build(nums,mid+1,end,right); //used recursive call to fill the cells
    tree[tn]=tree[left]+tree[right];
}

void segmentTree(vector<int> nums){
    int n=nums.size();
    tree.resize(2*n);
    build(nums,0,n-1,1);
}



//end copy here

int main(){
    vector <int> nums={1,2,3,4,5};
    //just update the nums array for a new question and press run no more changes needed
    segmentTree(nums);
    display(nums);
    display(tree);//tree is in global scope hence we dont pass the tree neither do we return the tree

    //updating a segment tree
    //{1,2,3,4,5}=>{1,2,99,4,5}
    int update_index=2;
    int update_val=99;
    //since tree is in global scope we use void functions to do our stuff and we dont even pass the tree to update function

    return 0;
}