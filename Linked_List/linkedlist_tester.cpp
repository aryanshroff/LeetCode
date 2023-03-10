#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };





void printll(ListNode *head){
    
    ListNode *curr=head;
    while(curr!=NULL){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
    cout<<endl;
    cout<<endl;
}

ListNode *llcreater(vector<int> v,ListNode *head){
    ListNode *curr=head;
    for(int i=0;i<v.size();i++){
        if(head==NULL){
            head=new ListNode(v[i]);
            curr=head;
            continue;
        }
        ListNode *temp=new ListNode(v[i]);
        curr->next=temp;
        curr=curr->next;
    }
    return head;
}

void addNode(ListNode *&curr,int x){
    ListNode *temp=new ListNode(x);
    curr->next=temp;
    curr=temp;
    return;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=l1;
        ListNode *curr=head;
        ListNode *parent=NULL;
        int stage=0;
        int sum{0},carry{0},digit{0};
        while(l1!=NULL and l2!=NULL){
           sum=l1->val+l2->val+carry;
            stage=1;
            digit=sum%10;
            curr->val=digit;
            parent=curr;
            curr=curr->next;
            l1=l1->next;
            l2=l2->next;
            carry=sum/10;
            cout<<"Inside while1 "<<endl;
            printll(head);
        }//we reach here means 
        
        //l1 exhausted
        while(l1==NULL and l2!=NULL){
            stage=2;
            curr=parent;
            sum=l2->val+carry;
            digit=sum%10;
            addNode(curr,digit); //curr equals to leaf node
            l2=l2->next;
            carry=sum/10;
            parent=curr;
            cout<<"Inside while2 and parent is: "<<parent->val<<endl;
            printll(head);
        }//here both l1 , l2 are exhausted
        
        //l2 exhasuted
        while(l2==NULL and l1!=NULL){
            stage=3;
            sum=l1->val+carry;
            digit=sum%10;
            curr->val=digit;
            parent=curr;
            curr=curr->next;
            carry=sum/10;
            l1=l1->next;
            cout<<"Inside while3 and parent is: "<<parent->val<<endl;
            printll(head);
        }//here l1 and l2 both are exhausted
        
        
        if(carry!=0){
            cout<<"carry check, before addNode ";
            printll(head);
            addNode(parent,carry);
            cout<<"carry check, after addNode ";
            printll(head);
        }
        return head;
        
    }

void reorderList(ListNode* head) {
        ListNode *p1{head},*p2{head},*slow{head},*fast{head},*limit{head},*parent{head};
    
        cout<<"Given linked list: ";
        printll(head);
        while(true){
            if(fast==NULL or fast->next==NULL){
                limit=slow;
                break;
            }
            slow=slow->next;
            fast=fast->next->next;
        }//at the end of this while our limit is middle element
        //we have to reverse the links from fast to limit
        cout<<"Middle element: "<<limit->val<<" slow:  "<<slow->val<<endl;
        p1=limit;
        p2=limit->next;
        limit->next=NULL;
        while(true){
            if(p2==NULL){
                //when p2 is null , p1 is its parent i.e leaf node
                fast=p1;
                break;
            }
            parent=p2->next;
            p2->next=p1;
            p1=p2;
            p2=parent;
        }
        //at the end of this loop our ll is reversed
        cout<<"Linked list after 2nd half reversal: ";
        printll(head);
        p1=head;
        p2=fast;
        ListNode *x{p1},*y{p2};
        while(true){
            if(p2->next==NULL){
                break;
            }
            x=p1->next;
            y=p2->next;
            p1->next=p2;
            p2->next=x;
            p1=x;
            p2=y;
            
        }
        cout<<"Linked list after re-order: ";
        printll(head);
        
    }

int main(){
    vector <int> v1={1,2,3,4,5,6};
    vector<int>  v2={1,2,3,4,5,6,7};
    
    ListNode *l1=llcreater(v1,NULL);
    ListNode *l2=llcreater(v2,NULL);
    reorderList(l1);
    cout<<endl;
    reorderList(l2);

    
    return 0;
}