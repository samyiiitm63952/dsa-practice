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
    int pairSum(ListNode* head) {
        if(head==NULL)return 0;
        stack<int>st;
        int n =0;
        ListNode* temp = head;
        while(temp!=NULL){
            st.push(temp->val);
            temp = temp->next;
            n++;
        }
        int ans = INT_MIN;
        temp = head;
        for(int i =0;i<n/2;i++){
            ans = max(ans,st.top()+temp->val);
            st.pop();
            temp=temp->next;
        }
        return ans;
    }
};