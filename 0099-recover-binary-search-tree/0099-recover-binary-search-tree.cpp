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
    TreeNode* first =NULL;
    TreeNode* second =NULL;
    TreeNode* prev = NULL;

    void solver(TreeNode* root){
        if(root==NULL)return;
        solver(root->left);
        if(prev && root->val < prev->val){
            if(first == NULL)first = prev;
                second = root;
        }
        prev = root;
        solver(root->right);
    }

    void recoverTree(TreeNode* root) {  
        solver(root);
        swap(first->val,second->val);
    }
};