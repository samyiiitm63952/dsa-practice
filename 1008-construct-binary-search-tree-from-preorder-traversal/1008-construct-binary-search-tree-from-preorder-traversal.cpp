class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        TreeNode* root = new TreeNode(preorder[0]);

        for(int i = 1; i < preorder.size(); i++) {

            TreeNode* curr = root;
            TreeNode* parent = nullptr;

            while(curr) {
                parent = curr;

                if(preorder[i] < curr->val)
                    curr = curr->left;
                else
                    curr = curr->right;
            }

            if(preorder[i] < parent->val)
                parent->left = new TreeNode(preorder[i]);
            else
                parent->right = new TreeNode(preorder[i]);
        }

        return root;
    }
};