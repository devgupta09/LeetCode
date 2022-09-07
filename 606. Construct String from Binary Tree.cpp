class Solution {
public:
    string tree2str(TreeNode* root) {
        if(!root) return "";
        string ans = to_string(root->val);
        if(!root->left and !root->right) return ans;             
        ans+='(' + tree2str(root->left) + ')' ;
        if(root->right) ans+='(' + tree2str(root->right) + ')';
        return ans;
    }
};
