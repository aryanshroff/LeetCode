#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printll(ListNode *head)
{

    ListNode *curr = head;
    while (curr != NULL)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
    cout << endl;
}

ListNode *llcreater(vector<int> v, ListNode *head)
{
    ListNode *curr = head;
    for (int i = 0; i < v.size(); i++)
    {
        if (head == NULL)
        {
            head = new ListNode(v[i]);
            curr = head;
            continue;
        }
        ListNode *temp = new ListNode(v[i]);
        curr->next = temp;
        curr = curr->next;
    }
    return head;
}

ListNode *reverse(ListNode*head){
    if(head==NULL){
        return NULL;
    }
    else if(head->next==NULL){
        return head;
    }
    ListNode *p1{head};
    ListNode *p2=p1->next,*p3=p2->next;
    p1->next=NULL;
    while(p3!=NULL){
        p2->next=p1;
        p1=p2;
        p2=p3;
        p3=p3->next;
    }
    p2->next=p1;
    //p2 is the current head
    return p2;
}

ListNode *dropnodes(ListNode *head){
    if(head==NULL or head->next==NULL){
        return head;
    }
    int high=head->val;
    ListNode *curr=head;
    while(curr->next!=NULL){
        if(curr->next->val>=high){
            high=curr->next->val;
            curr=curr->next;
        }
        else{
            ListNode *temp=curr->next;
            curr->next=temp->next;
            delete temp;
        }
    }
    return head;
}

int main(){
    //vector<int> v={5,2,13,4,8};
    vector<int> v={99,45,22,11,8,6,2};
    ListNode *head=llcreater(v,NULL);
    printll(head);
    head=reverse(head);
    printll(head);
    head=dropnodes(head);
    head=reverse(head);
    printll(head);
}