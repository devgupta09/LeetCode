class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(begin(properties),end(properties),cmp);
        int maxi = INT_MIN  , ans=0 , n=properties.size();
        for(int i=n-1;i>=0;i--){
            if(properties[i][1]>=maxi){
                maxi=properties[i][1];
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};
