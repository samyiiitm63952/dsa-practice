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
    stack<TreeNode*>stn;
    stack<TreeNode*>stp;

     void pushAll(TreeNode* root, bool reverse) {
        while (root) {
            if (reverse) {
                stp.push(root);
                root = root->right;
            } else {
                stn.push(root);
                root = root->left;
            }
        }
    }

    int next(){
        TreeNode* temp = stn.top();
        stn.pop();
        pushAll(temp->right,false);
        return temp->val;
    }
    int prev(){
        TreeNode* temp = stp.top();
        stp.pop();
        pushAll(temp->left,true);
        return temp->val;
    }


    bool findTarget(TreeNode* root, int k) {
        pushAll(root,true);
        pushAll(root,false);
        int i = next();
        int j = prev();
        while(i<j){
            if(i+j > k){
                j = prev();
            }
            else if(i+j <k){
                i = next();
            }
            else {
                return true;
            }
        }
        return false;
    }
};