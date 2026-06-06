class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;

        if(root == NULL) return ans;

        stack<TreeNode*> st;

        st.push(root);

        while(!st.empty()) {

            TreeNode* temp = st.top();
            st.pop();

            ans.push_back(temp->val);

            if(temp->left)
                st.push(temp->left);

            if(temp->right)
                st.push(temp->right);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};