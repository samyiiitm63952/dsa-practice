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
    int dia=0;
    int height(TreeNode* root){
        if(root==NULL)return 0;
        int left = height(root->left);
        int right = height(root->right);
        return max(left,right)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int lh = height(root->left);
        int rh=height(root->right);
        dia = max(dia,lh+rh);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return dia;

    }
};