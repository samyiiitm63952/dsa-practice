#include<iostream>
#include<algorithm>
#include<vector>

class node {
    public:
    int data;
    node* next;
    node(int val,node*next){
        this->data=val;
        this->next=next;
    }
    node(int val){
        this->data=val; 
        this->next=nullptr;
    }
};
node* convert(vector<int >arr){
    node* head=new node(arr[0]);
    node* temp=new node(arr[1]);
    head->next=temp;
    for(int i=2;i<arr.size();i++){
        temp->next=new node(arr[i]);
        temp=temp->next;
    }

    return head;
}