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
    void preorder(vector<int>&ans,TreeNode*root){
        if(root==NULL){
        ans.push_back(INT_MIN);
        return;}
        ans.push_back(root->val);
        preorder(ans,root->left);
        preorder(ans,root->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>ap;
        vector<int>aq;
        preorder(ap,p);
        preorder(aq,q);
        if(ap.size()!=aq.size()){return false;}
        for(int i=0;i<ap.size();i++){
            if(ap[i]!=aq[i]){return false;}
        }
        return true;
    }
};