#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    static int counter;
    int profit;
    int id;
    Node(int profit)
    {
        this->profit = profit;
        this->id=counter;
        counter++;
    }
    void display(){
        cout<<"id: "<<id<<" profit: "<<profit<<endl;
    }
};
int Node::counter = 0;


int main()
{
    vector <int> v={23,45,12,33,87,54};
    vector <Node> obj_vector;
    for(int i=0;i<v.size();i++){
        Node x(v[i]);
        obj_vector.push_back(x);
    }
    for(int i=0;i<obj_vector.size();i++){
        Node x=obj_vector[i];
        x.display();
    }
    return 0;
}