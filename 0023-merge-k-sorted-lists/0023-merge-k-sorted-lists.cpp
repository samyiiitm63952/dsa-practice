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
    void push_data(ListNode* head,vector<int>&ans){
        ListNode* temp= head;
        while(temp!=NULL){
            ans.push_back(temp->val);
            temp=temp->next;
        }
    }



    ListNode* mergeKLists(vector<ListNode*>& lists) {
  
        vector<int> ans;
        for(int i=0;i<lists.size();i++){
            push_data(lists[i],ans);
        }
        if(ans.size()==0)return NULL;
        sort(ans.begin(),ans.end());
        ListNode* head= new ListNode(ans[0]);
        ListNode* temp=head;
        for(int i=1;i<ans.size();i++){
            
            ListNode* adder=new ListNode(ans[i]);
            temp->next=adder;
            temp=adder;
        }
        return head;
    }
};