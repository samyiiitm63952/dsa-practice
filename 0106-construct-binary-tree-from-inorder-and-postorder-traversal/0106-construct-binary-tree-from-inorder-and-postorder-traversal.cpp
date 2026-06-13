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
    TreeNode* solver(vector<int>& inorder,int InStart,int InEnd,vector<int>& postorder,int PostStart,int PostEnd,unordered_map<int,int>& mpp){
        if(InStart>InEnd || PostStart>PostEnd){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[PostEnd]);
        int inroot = mpp[postorder[PostEnd]];
        int numsleft = inroot -InStart;
        root->left = solver(inorder , InStart,inroot -1,postorder,PostStart,PostStart+numsleft-1,mpp);
        root->right = solver(inorder ,inroot+1,InEnd,postorder,PostStart+numsleft,PostEnd-1,mpp);
        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* ans = solver(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
        return ans;
    }
};