#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print1d(vector<T> v){
    cout<<" 1D VECTOR "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
}

template <typename T> 
void print2d(vector<vector<T>> v){
    cout<<" 2D VECTOR "<<endl;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}

template <typename T>
void printstack(stack<T> s ){
    cout<<" STACK "<<endl;
    while(s.empty()==false){
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl;
    cout<<endl;
}

template <typename T>
void printq(queue<T> q){
    cout<<" QUEUE "<<endl;
    while(q.empty()==false){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    cout<<endl;
}

template <class K ,class V>
void printhash(unordered_map<K,V> h){
    cout<<" HASHMAP "<<endl;
    for(auto it=h.begin();it!=h.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<endl;
    cout<<endl;
}

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





int main()
{
    
    return 0;
}