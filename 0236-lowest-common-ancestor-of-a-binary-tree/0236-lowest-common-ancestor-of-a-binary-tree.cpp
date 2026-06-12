/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool solver(TreeNode* p,TreeNode* root,vector<TreeNode*>& pv){
        if(root==NULL)return false;
        pv.push_back(root);
        if(root==p){
            return true;
        }
        if(solver(p,root->left,pv)|| solver(p,root->right,pv))return true;
        pv.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>pv;
        vector<TreeNode*>qv;
        solver(p,root,pv);
        solver(q,root,qv);
        int i=0;
        int j=0;
        TreeNode* ans = NULL;
        while(i<pv.size() && j<qv.size()){
            if(pv[i]==qv[i]){
                ans=pv[i];
                i++;
                j++;
                continue;
            }
            else{
                break;
            }
        }    
        return ans;

    }
};