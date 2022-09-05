class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>v;
            while(size--){
                auto it=q.front();
                q.pop();
                v.push_back(it->val);
                for(auto i:it->children){
                    q.push(i);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};
