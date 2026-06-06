class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;

        stack<TreeNode*> st;

        TreeNode* curr = root;
        TreeNode* lastVisited = NULL;

        while(curr != NULL || !st.empty()) {

            // Go as left as possible
            if(curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            else {

                TreeNode* temp = st.top();

                // If right subtree exists and not processed yet
                if(temp->right != NULL &&
                   lastVisited != temp->right) {

                    curr = temp->right;
                }
                else {

                    ans.push_back(temp->val);

                    lastVisited = temp;

                    st.pop();
                }
            }
        }

        return ans;
    }
};