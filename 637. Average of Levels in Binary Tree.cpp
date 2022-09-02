class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            double x = 0;
            for(int i=0;i<size;i++){
                auto  it = q.front();
                q.pop();
                x+=it->val;
                if(it->left)  q.push(it->left);
                if(it->right) q.push(it->right);
            }
            ans.push_back((double)(x/size));
        }
        return ans;
    }
};
