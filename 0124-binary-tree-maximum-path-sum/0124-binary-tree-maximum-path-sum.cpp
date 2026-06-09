class Solution {
public:
    int ans = INT_MIN;

    int maxDown(TreeNode* root) {
        if (!root) return 0;

        int left = maxDown(root->left);
        int right = maxDown(root->right);

        return max(0, root->val + max(left, right));
    }

    void solve(TreeNode* root) {
        if (!root) return;

        int left = maxDown(root->left);
        int right = maxDown(root->right);

        ans = max(ans, left + right + root->val);

        solve(root->left);
        solve(root->right);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};