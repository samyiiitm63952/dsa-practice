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
    TreeNode* solver(vector<int>& preorder,int prestart,int preEnd ,vector<int>& inorder,int InStart,int InEnd ,unordered_map<int,int>&mpp){
      if(prestart > preEnd || InStart > InEnd)
    return NULL;
        TreeNode* root = new TreeNode(preorder[prestart]);
        int inroot = mpp[preorder[prestart]];
        int numsleft  = inroot- InStart;
         root->left = solver(preorder,prestart+1,prestart + numsleft, inorder , InStart,inroot-1,mpp);
         root->right = solver(preorder,prestart + numsleft +1, preEnd , inorder , inroot+1,InEnd,mpp); 
        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* ans= solver(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return ans;
    }
};