class Solution {
public:
    int recursive(vector<vector<int>> grid,int m,int n,vector<vector<int>> & dp){
        if(m==0 && n==0) return grid[0][0];
        if(m<0 || n<0) return INT_MAX;
        if(dp[m][n]!=-1) return dp[m][n];
        int left=recursive(grid,m-1,n,dp);
        int right=recursive(grid,m,n-1,dp);
        return dp[m][n]=grid[m][n]+min(left,right);

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        recursive(grid,m-1,n-1,dp);
        // dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=grid[i][j];
                    continue;
                }
                int up=INT_MAX;
                int left=INT_MAX;
                if(i>0){
                    up=dp[i-1][j];
                }
                if(j>0){
                    left=dp[i][j-1];
                }
                dp[i][j]=grid[i][j]+min(up,left);

            }
        }
        return dp[m-1][n-1];

        
        
    }
};
