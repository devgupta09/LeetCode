class Solution {
public:
    int dp[50][50];
    bool rec(int i,int j,string s,string t){
        if(i<0 and j<0)       return 1;
        if(i<0 and t[j]=='*') return rec(i,j-2,s,t);
        if(j<0 or i<0)        return 0;
        if(dp[i][j]!=-1)      return dp[i][j];
        if(s[i]==t[j] || t[j]=='.'){
            return dp[i][j] = rec(i-1,j-1,s,t);
        }
        if(t[j]=='*'){
            if(s[i]==t[j-1] || t[j-1]=='.'){
                return dp[i][j] = rec(i-1,j,s,t)|rec(i,j-2,s,t);
            }
            else{
                return dp[i][j] = rec(i,j-2,s,t);
            }
        }
        return dp[i][j] = 0;
    }
    bool isMatch(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return rec(s.length()-1,t.length()-1,s,t);
    }
};
