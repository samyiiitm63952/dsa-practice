class Solution {
public:

    void solve(TreeNode* root, int ht, int &mht) {

        if(root == NULL)
            return;

        mht = max(mht, ht);

        solve(root->left, ht + 1, mht);

        solve(root->right, ht + 1, mht);
    }

    int maxDepth(TreeNode* root) {

        if(root == NULL)
            return 0;

        int mht = 0;

        solve(root, 1, mht);

        return mht;
    }
};