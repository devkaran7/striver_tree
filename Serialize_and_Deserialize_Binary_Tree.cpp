class Codec {
private:
    TreeNode* getNext(string &data, int &i, int n){
        string ans = "";
        while(i < n && data[i] != ','){
            ans += data[i];
            i++;
        }
        i++;
        TreeNode* node = NULL;
        if(ans != "$"){
            int value = 0;
            bool first = true;
            for(auto it : ans){
                if(first && it == '-'){
                    first = false;
                    continue;
                }
                value = value * 10;
                value += it - '0';
            }
            node = new TreeNode((!first) ? -value : value);
        }
        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty() == false){
            TreeNode* node = q.front();
            q.pop();
            if(node){
                q.push(node->left);
                q.push(node->right);
                s += to_string(node->val);
            }else{
                s += "$";
            }
            s += ",";
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        int i = 0;
        queue<TreeNode*> q;
        TreeNode* root = getNext(data, i, n);
        if(root){
            q.push(root);
        }
        while(q.empty() == false){
            TreeNode* node = q.front();
            q.pop();
            node->left = getNext(data, i, n);
            if(node->left){
                q.push(node->left);
            }
            node->right = getNext(data, i, n);
            if(node->right){
               q.push(node->right);
            }
        }
        return root;
    }
};
