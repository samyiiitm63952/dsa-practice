/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solver(int &ans,TreeNode* root){
        if(root==NULL)return;
        solver(ans,root->left);
        ans++;
        solver(ans,root->right);
    }

    int countNodes(TreeNode* root) {
        int ans=0;
        if(root==NULL)return ans;
        solver(ans,root);
        return ans;
    }
};