class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int>m;
        vector<int>ans;
        for(auto i:changed){
            m[i]++;
        }
        sort(begin(changed),end(changed));
        for(auto i:changed){
            if(i==0){
                if(m[0]>=2){
                    ans.push_back(0);
                    m[0]-=2;
                }
                continue;
            }
            if(m[i]>0 and m[i*2]>0){
                ans.push_back(i);
                m[i*2]--;
                m[i]--;
            }
        }
        if(2*ans.size()!=changed.size()) return {};
        return ans;
    }
};
