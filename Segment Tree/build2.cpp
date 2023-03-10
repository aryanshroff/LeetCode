#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void display(vector <int> v);

/*IDEA
with tree as a global variable we dont need to pass tree to every function and also we dont need to retturn tree from every function if changes are 
made to the tree because tree is gloabl each function can access it and changes made will be permanent

the problem here is what if we need use of 2 segment trees in a problem statement , then isntead of implementing it via functional programing we 
use oop , so each object will correspond to its own nums value and its own tree value

ADVANTAGE
now i dont need to repeat my code
i can create as many nums,tree value pairs as many as i want with same blueprint of code

DISADVANTAGE
now instead of calling tree directly into int main i need to specify konsa object ka tree i am calling
cout<<tree[4]<<endl now becomes cout<<object1.tree[4]<<endl;
display(tree) now becomes display(object1.tree)
*/

/*LOGIC
1. start and end are with respect to nums array
    tn is with respect to tree array
*/

//copy from here
class SegmentTree{
    
    public:
    
    vector<int> tree;
    vector<int> nums;

    SegmentTree(vector<int> &v){
        nums=v;
    }

    void generate_segmentTree(){
        int n=nums.size();
        tree.resize(4*n); //always taking the size 4n
        build(0,n-1,1);
    }

    void build(int start,int end,int tn){
        //tn=>tree node i.e index at which filling will be done for this recursive call
        if(start==end){
            tree[tn]=nums[start];
            return;
        }
        int mid=(start/2)+(end/2);
        int left=tn*2;
        int right=left+1;
        build(start,mid,left);
        build(mid+1,end,right); //used recursive call to fill the cells
        tree[tn]=tree[left]+tree[right];
    }

    

    void update_segmentTree(int index,int value){
        //an intermediate function to pass default values to update function
        int n=nums.size();
        update(index,value,0,n,1);
    }

    void update(int index,int value,int start,int end,int tn){
        if(start==end){
            //we are updating nums and tree both on base case
            nums[index]=value;
            tree[tn]=value;
            //when start==end tn also becomes equal to index
            return;
        }

        int mid=start/2 + end/2;
        int left=2*tn;
        int right=left+1;
        if(index>mid){
            //we call update on rhs
            update(index,value,mid+1,end,right);
        }
        else{
            update(index,value,start,mid,left);
        }
        //children cells have been updated
        //time to update parent cell
        tree[tn]=tree[left]+tree[right];
    }

    int obtain_segment_sum(int left,int right){
        //left and right are the bloundaries of segment given by user
        //both inclusive 
        //start , end are boundaries of a particular node
        int n=nums.size();
        return query(left,right,0,n-1,1);
    }
    int query(int left,int right,int start,int end,int tn){
        //complete outside
        if(start>right or end<left){//start and end are boundaries of that node
            return 0;

        }
        //complete inside
        if(left<=start and right>=end){
            return tree[tn];
        }
        //partial inside->left se bhi answer mangwana hai , right se bhi answer mangwana hai
        else{
            int mid=start/2 + end/2;
            return query(left,right,start,mid,2*tn)+query(left,right,mid+1,end,2*tn+1);
        }
        
        

    }


};
//copy ends here

void display(vector <int> v){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        cout<<endl;
}






int main(){
    /*GENERATING A SEGMENT TREE
    1. create your object in form of ```classsname objectname(object_parameter)```
        the object paramter passed goes into construtor
        ->create your nums array, create object ,pass nums into the object

    2. to generate the segment tree ```objectname.generate_segmentTree()```
        i.e directly copy lines 83,84 into your code to generate segment tree
    */
    vector <int> nums={1,2,3,4,5};
    //just update the nums array for a new question and press run no more changes needed
    SegmentTree object1(nums);
    object1.generate_segmentTree();
    display(object1.nums);
    display(object1.tree);
    
    /*UPDATING A SEGMENT TREE
    1.{1,2,3,4,5}=>{1,2,99,4,5}
    update value=99
    update index=2
    */
   object1.update_segmentTree(2,10);
   display(object1.nums);
    display(object1.tree);


    /*FINDING SEGMENT SUM
    */
   int sum=object1.obtain_segment_sum(2,4);
   cout<<"segment sum: "<<sum<<endl;

    return 0;
}