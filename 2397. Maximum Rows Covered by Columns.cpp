class Solution {
public:
    int rec(int idx,vector<vector<int>>mat,int cols){
        int n=mat.size()  ,m=mat[0].size();
        if(cols==0){
            int x=0;
            for(int i=0;i<n;i++){
                bool f=1;
                for(int j=0;j<m;j++){
                    // cout<<mat[i][j]<<" ";
                    if(mat[i][j]==1){
                        f=0;
                    }
                }
                // cout<<endl;
                if(f)x++;
            }
            return x;
        }
        if(idx==m || cols<0) return -1e8;
        int ans=rec(idx+1,mat,cols);
        for(int i=0;i<n;i++){
            if(mat[i][idx]==1){ 
                mat[i][idx]=0;
            }
        }
        return max(ans,rec(idx+1,mat,cols-1));
    }
    int maximumRows(vector<vector<int>>& mat, int cols) {
        return rec(0,mat,cols);
    }
};
