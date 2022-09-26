class Solution {
private:
    int findleft(TreeNode* root){
        int h = 0;
        while(root){
            root = root->left;
            h++;
        }
        return h;
    }
private:
    int findright(TreeNode* root){
        int h = 0;
        while(root){
            root = root->right;
            h++;
        }
        return h;
    }
public:
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int lh = findleft(root);
        int rh = findright(root);
        if(lh == rh){
            return (1 << lh) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

Time -> Worst Case O(Log^2 N)
Space -> O(Log N)
