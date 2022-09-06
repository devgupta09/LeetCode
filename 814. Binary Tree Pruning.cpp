class Solution {
public:
    int rec(TreeNode* &root){
        if(!root) return 0;
        int left = rec(root->left);
        int right = rec(root->right);
        if(left==0) root->left = NULL;
        if(right==0)root->right= NULL;
        return left + right + root->val;
    }
    TreeNode* pruneTree(TreeNode* root) {
        rec(root);
        if(!root->left and !root->right and root->val==0) return NULL;
        return root;
    }
};
