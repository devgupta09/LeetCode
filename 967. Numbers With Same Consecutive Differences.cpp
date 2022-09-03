class Solution {
public:
    vector<int>ans;
    void rec(int n,int k,int x){
        if(n==0){
            ans.push_back(x);
            return;
        }
        for(int i=0;i<=9;i++){
            if(x==0){
                if(i>0){
                    rec(n-1,k,i);
                }
            }
            else{
                if(abs(x%10 - i)==k){
                    rec(n-1,k,x*10 + i);
                }
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        rec(n,k,0);
        return ans;
    }
};
