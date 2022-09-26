class Solution {
private:
    TreeNode* rec(vector<int>& in, vector<int> &post, int &i, int n, int l, int r){
        TreeNode* node = new TreeNode(post[i]);
        if(l == r){
            return node;
        }
        for(int x = l; x <= r; x++){
            if(in[x] == post[i]){
                if(x + 1 <= r){
                   i--;
                    node->right = rec(in, post, i, n, x + 1, r); 
                }
                if(l <= x - 1){
                    i--;
                    node->left = rec(in, post, i, n, l, x-1);
                }
                break;
            }
        }
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int i = n-1;
        return rec(inorder, postorder, i, n, 0, n-1);
    }
};
