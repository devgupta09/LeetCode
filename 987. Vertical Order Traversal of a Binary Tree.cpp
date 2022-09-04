class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {{}};
        map<int,map<int,multiset<int>>>m;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        vector<vector<int>>ans;
        while(!q.empty()){
            auto it=q.front().first;
            auto x =q.front().second.first;
            auto y =q.front().second.second;
            q.pop();
            m[x][y].insert(it->val);
            if(it->left) q.push({it->left,{x-1,y+1}});
            if(it->right) q.push({it->right,{x+1,y+1}});
        }
        for(auto i:m){
            vector<int>v;
            for(auto j:i.second){
                for(auto k:j.second){
                    v.push_back(k);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};
