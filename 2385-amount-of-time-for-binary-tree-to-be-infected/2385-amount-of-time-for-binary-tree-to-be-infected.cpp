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
    void pmake(unordered_map<TreeNode*,TreeNode*>&psave,TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i =0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left){
                    q.push(curr->left);
                    psave[curr->left]=curr;
                }
                if(curr->right){
                    q.push(curr->right);
                    psave[curr->right]=curr;
                }
            }
        }
    }


    void finder(TreeNode* & starti,TreeNode* root,int start){
        if(root==NULL)return ;
        if(root->val==start){
            starti = root;
        }
        finder(starti,root->left,start);
        finder(starti,root->right,start);

    }


    int amountOfTime(TreeNode* root, int start) {
        int ans =0;
        if(root==NULL)return ans;
        unordered_map<TreeNode*,TreeNode*>psave;
        pmake(psave,root);
        unordered_map<TreeNode*,bool>visi;
        queue<TreeNode*>q;
        TreeNode* starti;
        finder(starti,root,start);
        q.push(starti);
        visi[starti]=true;
        while(!q.empty()){
            int size= q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left && !visi[curr->left]){
                    q.push(curr->left);
                    visi[curr->left]=true;
                }
                if(curr->right && ! visi[curr->right]){
                    q.push(curr->right);
                    visi[curr->right]=true;
                }
                if(psave[curr]!=NULL && !visi[psave[curr]] ){
                    q.push(psave[curr]);
                    visi[psave[curr]]=true;
                }
            }
            ans++;
        }
        return ans-1;
    }
};