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
    void inorder(vector<int>& ans,TreeNode* root){
        if(root==NULL)return;
        inorder(ans,root->left);
        ans.push_back(root->val);
        inorder(ans,root->right);

    }

    void solver(vector<int>& sorted,TreeNode * root,int& i){
        if(root==NULL)return;
        solver(sorted,root->left,i);
        if(root->val != sorted[i] ){
            root->val = sorted[i];
        }
        i++;
        solver(sorted,root->right,i);
    }    

    void recoverTree(TreeNode* root) {
        vector<int>sorted;
        inorder(sorted,root);
        sort(sorted.begin(),sorted.end());
        int i =0;
        solver(sorted,root,i);

    }
};