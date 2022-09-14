class Solution {
public:
    
    void rec(TreeNode* root,vector<int>&m,int &cnt){
        if(!root){
            return ;
        }
        m[root->val]++;
        if(root->left==NULL and root->right==NULL){
            cnt+=ispal(m);
        }
        if(root->left) rec(root->left,m,cnt);
        if(root->right) rec(root->right,m,cnt);
        m[root->val]--;
    }
    
    bool ispal(vector<int>&m){
        int n=0,cnt=0;
        for(auto i=0;i<10;i++){
            n+=m[i];
        }
        for(auto i=0;i<10;i++){
            if(m[i]%2==1 and n%2==1){
                if(cnt==0){
                    cnt++;
                }
                else{
                    return 0;
                }
            }
            else if(n%2==0 and m[i]%2==1){
                return 0;
            }
        }
        return 1;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>v(10,0);
        int cnt=0;
        rec(root,v,cnt);
        return cnt;
    }
    
};
