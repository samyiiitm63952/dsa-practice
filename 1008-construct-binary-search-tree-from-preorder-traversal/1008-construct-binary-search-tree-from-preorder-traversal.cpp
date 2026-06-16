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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i =0;
        return solver(INT_MAX,preorder,i);
    }
    TreeNode* solver(int ub,vector<int>& preorder,int& i){
        if(i == preorder.size() || preorder[i]>ub)return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = solver(root->val,preorder,i);
        root->right = solver(ub,preorder,i);
        return root;
    }
};