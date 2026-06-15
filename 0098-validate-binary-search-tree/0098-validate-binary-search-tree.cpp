/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solver(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
            return;
        solver(root->left, ans);
        ans.push_back(root->val);
        solver(root->right, ans);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        solver(root, ans);
        for (int i = 1; i < ans.size(); i++) {
            if (ans[i] <= ans[i - 1])
                return false;
        }
        return true;
    }
};