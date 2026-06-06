class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        stack<TreeNode*> st;

        TreeNode* node = root;

        while(node != NULL || !st.empty()) {

            // go left
            while(node != NULL) {
                st.push(node);
                node = node->left;
            }

            // process node
            node = st.top();
            st.pop();

            ans.push_back(node->val);

            // move right
            node = node->right;
        }

        return ans;
    }
};