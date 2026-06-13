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
   void dfs(TreeNode* root, vector<TreeNode*>& pre){
    if(!root) return;

    pre.push_back(root);

    dfs(root->left, pre);
    dfs(root->right, pre);
}

void flatten(TreeNode* root) {

    if(!root) return;

    vector<TreeNode*> pre;

    dfs(root, pre);

    for(int i=0;i<pre.size()-1;i++){

        pre[i]->left = NULL;
        pre[i]->right = pre[i+1];
    }

    pre.back()->left = NULL;
    pre.back()->right = NULL;
}
};