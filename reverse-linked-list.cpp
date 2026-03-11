#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main(){
    cout<<"i changed Reverse Linked List Example";
}
