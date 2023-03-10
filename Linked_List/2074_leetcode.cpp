#include <iostream>
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

void display(vector<pair<int, int>> v2)
{
    cout << "[";
    for (auto x : v2)
    {
        cout << "<" << x.first << "," << x.second << "> ";
    }
    cout << "]";
    cout << endl;
}



//basic ends here

vector<pair<int, int>> generateIntervals(ListNode *head)
{
    vector<pair<int, int>> v1;
    int n = 0;
    ListNode *curr = head;
    while (curr != NULL)
    {
        n++;
        curr = curr->next;
    }
    // size of linked list has been obtained
    int grp = 2;
    while (true)
    {
        int startIndex = (grp * (grp - 1) / 2) + 1;
        if (startIndex > n)
        {
            break;
        }
        int endIndex = startIndex + grp - 1;
        if (endIndex > n)
        {
            int diff = 1 + n - startIndex;
            if (diff % 2 == 0)
            {
                // grp has even elements
                endIndex = n;
            }
            else
            {
                // grp has odd elements
                break;
            }
        }
        pair<int, int> p;
        p.first = startIndex;
        p.second = endIndex;
        v1.push_back(p);
        grp += 2;
    }
    // by now our vector of indexes has been generated
    return v1;
}

ListNode *reverseByIntervals(ListNode *head, vector<pair<int, int>> v1)
{
    ListNode *curr = head;
    ListNode *dummy = new ListNode(0, head);
    ListNode *parent = dummy;
    int count = 1; // 1 indexed linked list
    int ind = 0;
    cout<<count<<" , "<<ind<<endl;
    while (curr != NULL)
    {   
        if(ind>v1.size()-1){
            break;
        }
        int startIndex = v1[ind].first;
        if (count == startIndex)
        {
            ListNode *p1 = parent;
            ListNode *p2 = curr;
            ListNode *p3 = curr;
            ListNode *p4 = curr;
            ListNode *x = curr;
            ListNode *y = curr;
            ListNode *z = curr;
            while (true)
            {
                y = x->next;
                z = y->next;
                y->next = x;
                x = y;
                y = z;
                count++;
                cout<<count<<" , "<<ind<<endl;

                if (count == v1[ind].second)
                {
                    p4 = z;
                    p3 = y;
                    p1->next = p3;
                    p2->next = p4;
                    curr=z;
                    parent=y;
                    ind++;
                    break;
                }
            }
        }
        curr = curr->next;
        parent = parent->next;
        count++;
    }
    return dummy->next;
}

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    ListNode *l1 = llcreater(v1, NULL);
    printll(l1);
    vector<pair<int, int>> v2 = generateIntervals(l1);
    display(v2);
    ListNode *l2 = reverseByIntervals(l1, v2);
    printll(l2);
    return 0;
}