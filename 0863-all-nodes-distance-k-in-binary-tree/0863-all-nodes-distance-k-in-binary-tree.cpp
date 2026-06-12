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
    void fpsave(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& psave){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
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

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(root==NULL)return ans;
        unordered_map<TreeNode*,TreeNode*>psave;
        fpsave(root,psave);
        unordered_map<TreeNode*,bool>visi;
        queue<TreeNode*>q;
        q.push(target);
        visi[target]=true;
        int curr_dist=0;
        while(!q.empty()){
            int size = q.size();
            if(curr_dist==k)break;
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left && !visi[curr->left]){
                    q.push(curr->left);
                    visi[curr->left]=true;
                }
                if(curr->right && !visi[curr->right]){
                    q.push(curr->right);
                    visi[curr->right]=true;
                }
                if(psave[curr]!=NULL && !visi[psave[curr]]){
                    q.push(psave[curr]);
                    visi[psave[curr]]=true;
                }
            }curr_dist++;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};