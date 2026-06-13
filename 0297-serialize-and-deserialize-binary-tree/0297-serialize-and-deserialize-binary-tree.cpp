class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";

        string ans = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if(curr == NULL) {
                ans += "#,";
                continue;
            }

            ans += to_string(curr->val) + ",";

            q.push(curr->left);
            q.push(curr->right);
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;

        stringstream ss(data);
        string str;

        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            if(getline(ss, str, ',')) {
                if(str != "#") {
                    node->left = new TreeNode(stoi(str));
                    q.push(node->left);
                }
            }

            // Right child
            if(getline(ss, str, ',')) {
                if(str != "#") {
                    node->right = new TreeNode(stoi(str));
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};