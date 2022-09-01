class Solution {
public:
    int rec(TreeNode* root,int maxi){
        if(!root) return 0;
        int left = rec(root->left , max(maxi,root->val));
        int right= rec(root->right, max(maxi,root->val));
        return left +right + (maxi<=root->val);
    }
    int goodNodes(TreeNode* root) {
        return rec(root,INT_MIN);
    }
};
