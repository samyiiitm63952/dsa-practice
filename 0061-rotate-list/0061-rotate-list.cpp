class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: find length
        ListNode* temp = head;
        int n = 1;
        while (temp->next) {
            temp = temp->next;
            n++;
        }

        // Step 2: reduce k
        k = k % n;
        if (k == 0) return head;

        // Step 3: make circular
        temp->next = head;

        // Step 4: find new tail
        int steps = n - k;
        ListNode* newTail = head;
        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

        // Step 5: break circle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};