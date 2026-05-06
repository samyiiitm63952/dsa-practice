/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return nullptr;
        if(head->next==NULL)return head;
        ListNode* curr=head;
        int n=0;
        while (curr!=NULL){
            curr=curr->next;
            n++;
        }
        k=k%n;
        while(k!=0){
             ListNode * curr =head->next; 
             ListNode * prev =head; while(curr->next!=NULL)
             {
                 prev=curr;
              curr=curr->next;
              } curr->next=head;
               head=curr;
                prev->next=NULL; k--; }
                return head;
    }
};