class Solution {
public:

    void solver(TreeNode* root, vector<string>& ans, string& curr) {

        if (root == NULL) {
            return;
        }

        int len = curr.size();

        curr += to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(curr);
        }
        else {
            solver(root->left, ans, curr);
            solver(root->right, ans, curr);
        }

        curr.resize(len);
    }

    int sumNumbers(TreeNode* root) {

        vector<string> ans;
        string curr;

        solver(root, ans, curr);

        int sum = 0;

        for (auto &s : ans) {
            sum += stoi(s);
        }

        return sum;
    }
};