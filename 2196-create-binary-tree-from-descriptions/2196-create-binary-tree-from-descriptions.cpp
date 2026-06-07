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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        vector<TreeNode*> nodes(100001,NULL);
        vector<bool> chnodes(100001,false);

        for(int i=0;i<descriptions.size();i++){

            int parent = descriptions[i][0];
            int child = descriptions[i][1];

            if(nodes[parent] == NULL){
                TreeNode* p = new TreeNode(parent);
                nodes[parent] = p;
            }

            if(nodes[child] == NULL){
                TreeNode* c = new TreeNode(child);
                nodes[child] = c;
            }

            if(descriptions[i][2] == 1){
                nodes[parent]->left = nodes[child];
            }
            else{
                nodes[parent]->right = nodes[child];
            }

            chnodes[child] = true;
        }

        for(int i=0;i<nodes.size();i++){

            if(nodes[i] != NULL && chnodes[i] == false){
                return nodes[i];
            }
        }

        return NULL;
    }
};