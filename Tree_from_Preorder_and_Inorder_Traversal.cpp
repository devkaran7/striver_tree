class Solution {
private:
    TreeNode* rec(vector<int> &preorder, vector<int> &inorder, int& i, int n, int l, int r){
        TreeNode* node = new TreeNode(preorder[i]);
        if(l == r){
            return node;
        }
        for(int x = l; x <= r; x++){
            if(inorder[x] == preorder[i]){
                if(l <= x-1){
                    i++;
                    node->left = rec(preorder, inorder, i, n, l, x-1);
                }else{
                    node->left = NULL;
                }
                if(x+1 <= r){
                    i++;
                    node->right = rec(preorder, inorder, i, n, x+1, r);
                }else{
                    node->right = NULL;
                }
                break;
            }
        }
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int i = 0;
        return rec(preorder, inorder, i, n, 0, n-1);
    }
};
