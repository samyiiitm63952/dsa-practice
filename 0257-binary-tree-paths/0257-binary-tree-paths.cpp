class Solution {
public:

    void solver(vector<string>& ans, string curr, TreeNode* root) {
        if (root == NULL) return;

        curr += to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(curr);
            return;
        }

        curr += "->";

        solver(ans, curr, root->left);
        solver(ans, curr, root->right);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        solver(ans, "", root);

        return ans;
    }
};